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

void	parent_process(char *envp[], char *argv, t_pipe *info, int fd[])
{
	close(fd[1]);
	info -> out_fd = open(argv, O_TRUNC | O_CREAT | O_RDWR, 0666);
//	printf("entering parent, out fd %i\n", info -> out_fd); //erase
	if (info -> out_fd == -1)
		print_error(strerror(1), 1, info);
	check_access(info, info->out_cmd, &(info->path2));
//	printf("parent after checking path: %s\n", info->path2); //erase
	if (dup2(info->out_fd, STDOUT_FILENO) < 0)
	{
		close(info->out_fd);
		print_error("dup2 file descriptor", 0, info);
	}
	close(info->out_fd);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(fd[0]);
	if (execve(info->path2, info->out_cmd, envp) < 0)
		print_error(info->out_cmd[0], 0, info);
}

void	child_process(char *envp[], char *argv, t_pipe *info, int fd[])
{
	char	**cmd;
	char	*the_path;

	cmd = decision_maker(info, argv, -1);
	the_path = NULL;
	if
	close(fd[0]);
//	printf("entering child, in fd %i\n", info->in_fd); //erase
	info -> in_fd = open(argv, O_RDONLY);
//	printf("entering child, in fd %i\n", info -> in_fd); //erase
//	printf("before execve path1: %s\n", info->path1);//erase
	if (info -> in_fd == -1)
		print_error(argv, 0, info);
//	printf("child before checking paths %s\n", info -> in_cmd[0]); //erase
	check_access(info, cmd, &the_path);
	if (dup2(info->in_fd, STDIN_FILENO) < 0)
	{
		close(info -> in_fd);
		print_error("dup2 file descriptor", 0, info);
	}
	close(info->in_fd);
//	printf("child after closing, in fd %i\n", info -> in_fd); //erase
//	printf("!!!!!!!!!!path1: %s -- in_cmd: %s %s\n", info->path1, info->in_cmd[0], info->in_cmd[1]);//erase
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		print_error("dub2 file descriptor", 0, info);
	close(fd[1]);
	if (execve(the_path, cmd, envp) == -1) //
		print_error(cmd[0], 0, info);
}

void	initialize_tpipe(t_pipe *info)
{
	info -> i = -1;
	info -> n = -1;
	info -> flag = 0;
	info -> in_fd = -1;
	info -> out_fd = -1;
	info -> paths = NULL;
	info -> here_doc = 0;
	info -> str_doc = NULL;
//	info -> path1 = NULL;
//	info -> path2 = NULL;
//	info -> in_cmd = NULL;
//	info -> out_cmd = NULL;
}

void	parse_all(char **argv, t_pipe *info, char *envp[], int i)
{
	initialize_tpipe(info);
//	printf("entering parsing: %s\n", argv[1]); //erase
//	info -> in_cmd = decision_maker(info, argv[2], -1);
//	info -> out_cmd = decision_maker(info, argv[3], -1);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
		//	printf("before splitting path: %s\n", envp[i]); //erase
			info -> paths = ft_split_path(info, envp[i] + 5, -1, -1);
			break ;
		}
	}
	if (!info->paths)
		info->paths = ft_split_path(info, DEF, -1, -1);
//	printf("after splitting path: %s\n", info->paths[1]); //erase
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*info;
	int		fd[2];
	int		pid;
	int		i;

	info = NULL;
	i = 0;
//	printf("argv cmd1: %s\n", argv[2]);//erase
	if (argc < 5)
		print_error("invalid arguments: Introduce at least 4 arguments\n", 22, info);
	info = malloc(sizeof(t_pipe));
	if (!info)
		print_error("malloc", 0, NULL);
	parse_all(argv, info, envp, -1);
//	printf("cmd2: %s\ncmd2: %s\n", info->out_cmd[0], info->out_cmd[1]);//erase
//	printf("path1: %s\npath2: %s\n", info->path1, info->path2);//erase
//	printf("cmd1: %s\ncmd1: %s\n", info->in_cmd[0], info->in_cmd[1]);//erase
//	printf("in fd: %i\nout fd: %i\n", info->in_fd, info->out_fd);//erase
	while (++i < argc - 1)
	{
		if (pipe(fd) < 0)
			print_error("pipe", 0, info);
	//exit (1);
		pid = fork(); //fork();
		if (pid < 0)
			print_error("fork", 0, info);
		if (i == 1 && !ft_strncmp(argv[1], "here_doc\0", ft_strlen(argv[1])))
		{
			while (42)
			{
				info -> str_doc = get_next_line(0);
				if (!info -> str_doc)
					print_error("get_next_line", 0, NULL);
				else if (!ft_strncmp(info -> str_doc, argv[2], ft_strlen(info -> str_doc)))
				{
					free(info -> str_doc);
					break ;
				}
				write(fd[1], info -> str_doc, ft_strlen(info->str_doc));
				// instead of this create another function with another pipe/ lok the erics way
			}
			i = i + 1;
		}
		if (pid == 0)
		{
			
			child_process(envp, argv[1], info, fd);
		}
	parent_process(envp, argv[4], info, fd);
	waitpid(pid, NULL, 0);
	return (0);
}
