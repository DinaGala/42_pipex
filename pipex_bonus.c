/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:29:07 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/17 16:47:27 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child_process(char *envp[], char *argv, t_pipe *info, char *outfile)
{
	char	*the_path;
	char	**cmd;

	the_path = NULL;
//	close(fd[1]);
//	printf("entering parent, in fd %i\n", info->in_fd); //erase
	cmd = decision_maker(info, argv, -1);

//	printf("entering parent, in fd %i\n", info->in_fd); //erase
	if (!info->here_doc)
		info -> out_fd = open(outfile, O_TRUNC | O_CREAT | O_RDWR, 0666);
	else
		info -> out_fd = open(outfile, O_APPEND | O_CREAT | O_RDWR, 0666);
//	printf("entering parent, fd %i\n", info ->out_fd); //erase
	if (info -> out_fd == -1)
		print_error(outfile, 0, info);
//	else
//	{
	if (dup2(info->out_fd, STDOUT_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
//		print_error("pipex: text: No such file or directory", 0, info);
//		
	close(info->out_fd);
//	}
//		perror(outfile);
//		print_error(outfile, 0, info);
//		print_error(strerror(1), 1, info);
	
	if (dup2(info->in_fd, STDIN_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(info->in_fd);
	check_access(info, cmd, &the_path);
//	printf("parent after checking path: %s\n", cmd[0]); //erase
	if (execve(the_path, cmd, envp) < 0)
		print_error(cmd[0], 0, info);
}

void	child_process(char *envp[], char *argv, t_pipe *info, char *infile)
{
	char	**cmd;
	char	*the_path;
//	int	bytes = 0; //erase
//	char	buf[2345]; //erase

	the_path = NULL;
//	printf("child before closing READ pipe, in pipe %i\n", info->fd[0]); //erase
	close(info->fd[0]);
//	printf("child after closing pipe, in pipe %i\n", info->fd[0]); //erase
	cmd = decision_maker(info, argv, -1);
//	printf("entering child, in fd %i\n", info->in_fd); //erase
	if (info -> in_fd == -1)
		info -> in_fd = open(infile, O_RDONLY);
	if (info -> in_fd == -1)
		print_error(infile, 0, info);
//	printf("child, in fd %i\n", info->in_fd); //erase
//	printf("entering child, cmd %s %s\n", cmd[0], cmd[1]); //erase
//	printf("before execve path1: %s\n", info->path1);//erase
//	if (info -> in_fd == -1)
//		write(2, strerror(2), ft_strlen(strerror(2)));
//		print_error(argv, 0, info);
//	printf("child before checking paths %s\n", info -> in_cmd[0]); //erase
//	bytes = read(info->in_fd, buf, sizeof(buf));
//	printf("inside file desc: %s\n", buf);
	check_access(info, cmd, &the_path);
//	if (info->in_fd != -1)
//	{

	if (dup2(info->in_fd, STDIN_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(info->in_fd);
//	}
//	close(info->in_fd);
//	printf("child after closing, in fd %i\n", info -> in_fd); //erase
//	printf("child before closing WRITE pipe, in pipe %i\n", info->fd[1]); //erase
//	printf("!!!!!!!!!!path1: %s -- in_cmd: %s %s\n", info->path1, info->in_cmd[0], info->in_cmd[1]);//erase
	if (dup2(info->fd[1], STDOUT_FILENO) < 0)
		print_error("dub2 file descriptor", 0, info);
	close(info->fd[1]);
//	write(2, "before execve", 13);
//	printf("child after closing pipe, in pipe %i\n", info->fd[1]); //erase
//	printf("child after everything: %s\n", cmd[0]); //erase
	if (execve(the_path, cmd, envp) == -1) //
		print_error(cmd[0], 0, info);
}

void	initialize_tpipe(t_pipe *info, char *envp[], char **argv)
{
	info -> i = 0;
	info -> n = -1;
	info -> flag = 0;
	info -> here_doc = 0;
	info -> str_doc = NULL;
//	printf("entering initialize, i %i\n", info->i); //erase
	while (envp[info->i] && !ft_strncmp(envp[info->i], "PATH=", 5))
		info->i++;
	if (envp[info->i] && ft_strncmp(envp[info->i], "PATH=", 5) == 0)
		info -> paths = ft_split_path(info, envp[info->i] + 5, -1, -1);
	else
		info->paths = ft_split_path(info, DEF, -1, -1);
//	info -> paths = NULL;		
//	printf("after splitting paths %s\n", info -> paths[0]); //erase
	info -> i = -1;
	info -> in_fd = -1;
	if (!ft_strncmp(argv[1], "here_doc\0", ft_strlen(argv[1])))
		info -> here_doc = 1;
	if (info -> here_doc)
		ft_here_doc(info, argv);
//	if (!info -> here_doc)
//		info -> in_fd = open(argv[1], O_RDONLY);
//	else
//		ft_here_doc(info, argv);
//	printf("here_doc: %i --- in_fd: %i\n", info->here_doc, info->in_fd); //erase
//	if (info -> in_fd == -1)
//	{
//		write(2, "pipex: ", 7);
//		perror(argv[1]);
//	}
//		print_error(argv[1], 0, info);
/*	{
		write(2, "pipex: ", 7);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, ": No such file or directory\n", 28);
	}*/
	info -> out_fd = -1;
//	info -> out_fd = open(argv[argc - 1], O_TRUNC | O_CREAT | O_RDWR, 0666);
//	printf("argc: %i --- out_fd: %i\n", argc, info->out_fd); //erase
//	if (info -> out_fd == -1)
//		print_error(argv[argc - 1], 0, info);
/*	{	
		write(2, "pipex: ", 7);
		write(2, argv[argc - 1], ft_strlen(argv[argc - 1]));
		write(2, ": No such file or directory\n", 28);
	}*/
}

void	ft_here_doc(t_pipe *info, char **argv)
{
	int	hd[2];

	if (pipe(hd) < -1)
		print_error("pipe", 0, info);
	while (42)
	{
		info -> str_doc = get_next_line(0);
	//	printf("delimiter: %s -- strlen %zu\n", argv[2], ft_strlen(argv[2]));//erase
	//	printf("gnl: %s -- strlen %zu\n", info -> str_doc, ft_strlen(info -> str_doc)); //erase
	//	printf("line: %s\n", info -> str_doc);//erase
		if (!info -> str_doc)
			print_error("get_next_line", 0, NULL);
		else if (!ft_strncmp(info -> str_doc, argv[2], ft_strlen(info -> str_doc) - 1))
		//	printf("last line: %s\n", info -> str_doc);//erase
			break ;
		write(hd[1], info -> str_doc, ft_strlen(info->str_doc));
	}
	free(info -> str_doc);
	info -> str_doc = NULL;
	close(hd[1]);
	info -> in_fd = hd[0];
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*info;
	int		pid;
	int		i;

	info = NULL;
	if (argc < 5)
		print_error("invalid arguments: Introduce at least 4 arguments\n", 22, info);
	info = malloc(sizeof(t_pipe));
	if (!info)
		print_error("malloc", 0, NULL);
	initialize_tpipe(info, envp, argv);
	if (!info -> here_doc)
		i = 1;
	else
		i = 2;
	while (++i < argc - 1)
	{
		if (i < argc - 2)
			pipe(info -> fd);
		if (info->fd < 0)
			print_error("pipe", 0, info);
		pid = fork();
		if (pid < 0)
			print_error("fork", 0, info);
		else if (pid == 0 && i < argc - 2)
			child_process(envp, argv[i], info, argv[1]);
		else if (pid == 0 && i == argc - 2)
			last_child_process(envp, argv[i], info, argv[i + 1]);
	//	waitpid(pid, NULL, 0);
		close (info->fd[1]);
		close (info->in_fd);
		info->in_fd = info->fd[0];
	//	printf("in main after fork i: %i, --- pid: %i\n", i, pid);
	}
//	waitpid(pid, NULL, 0);
	clean_up(info);  
//	parent_process(envp, argv[argc - 2], info);
	return (0);
}
