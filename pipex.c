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

#include "pipex.h"

void	parent_process(char *envp[], char *argv, t_pipe *info, int fd[])
{
	close(fd[1]);
	info -> out_fd = open(argv, O_TRUNC | O_CREAT | O_RDWR, 0666);
	printf("entering parent, out fd %i\n", info -> out_fd); //erase
	if (info -> out_fd == -1)
	{
	//	print_error(argv, -1, info);
		print_error(argv, 0, info);
	}
	if (dup2(info->out_fd, STDOUT_FILENO) < 0)
	{
		close(info->out_fd);
		print_error("dup2 file descriptor", 0, info);
	}
	close(info->out_fd);
	if (dup2(fd[0], STDIN_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(fd[0]);
//	execve(info->path2, info->out_cmd, envp);
	if (execve(info->path2, info->out_cmd, envp) < 0)
		print_error("cmd2", 0, info);
}

void	child_process(char *envp[], char *argv, t_pipe *info, int fd[])
{
	close(fd[0]);
//	printf("entering child, in fd %s\n", ); //erase
	info -> in_fd = open(argv, O_RDONLY);
	printf("entering child, in fd %i\n", info -> in_fd); //erase
	if (info -> in_fd == -1)
	{
	//	exit (0);
		print_error(argv, 0, info);
	}
	if (dup2(info->in_fd, 0) < 0)
	{
		close(info -> in_fd);
		print_error("dup2 file descriptor", 0, info);
	}
	close(info->in_fd);
//	printf("child after closing, in fd %i\n", info -> in_fd); //erase
//	printf("!!!!!!!!!!path1: %s -- in_cmd: %s %s\n", info->path1, info->in_cmd[0], info->in_cmd[1]);//erase
	if (dup2(fd[1], 1) < 0)
		print_error("dub2 file descriptor", 0, info);
	close(fd[1]);
//	execve(info->path1, info->in_cmd, envp);
	printf("child after closing, in fd %i\n", info -> in_fd); //erase
	if (execve(info->path1, info->in_cmd, envp) == -1) //
		print_error("cmd1", 0, info);
}

void	check_paths(t_pipe *info, char **paths)
{
	//first checking the scripts
	if (info->in_cmd[0][0] == '.' && info->in_cmd[0][1] == '/')
		info->path1 = check_access(&(&(" ")), ft_strdup(info->in_cmd[0]), info);//crazy stuff
	else
		info->path1 = ft_strdup(check_access(paths, info->in_cmd[0], info));
	if (info->out_cmd[0][0] == '.' && info->out_cmd[0][1] == '/')
		info->path2 = ft_strdup(info->out_cmd[0]);
	else
		info->path2 = ft_strdup(check_access(paths, info->out_cmd[0], info));
}

void	parse_all(char **argv, t_pipe *info, char *envp[], int i)
{
	char	**paths;

	paths = NULL;
	initialize_tpipe(info);
//	info -> in_cmd = ft_split_cmd(info, argv[2], ' ', -1); //you can send here to the decision maker
//	info -> out_cmd = ft_split_cmd(info, argv[3], ' ', -1);
	printf("entering parsing: %s\n", argv[1]); //erase
	info -> in_cmd = decision_maker(info, argv[2], -1);
	info -> out_cmd = decision_maker(info, argv[3], -1);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			paths = ft_split_path(info, envp[i] + 5, ':', -1);
			break ;
		}
	}
	if (!paths)
		paths = ft_split_path(info, DEFPATH, ':', -1);
	printf("after splitting path: %s\n", paths[1]); //erase
	check_paths(info, paths);
	printf("checking path: %s\n", paths[1]); //erase
	ft_free(paths, -1);
	if (info->path1 == NULL || info->path2 == 0)
		print_error("access", 127, info);
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*info;
	int		fd[2];
	int		pid;

	info = NULL;
	if (argc != 5)
		print_error("invalid arguments: Introduce 4 arguments\n", 22, info);
	info = malloc(sizeof(t_pipe));
	if (!info)
		print_error("malloc", 0, NULL);
//	exit (1); // erase
	parse_all(argv, info, envp, -1);
//	exit (1);
	printf("cmd2: %s\ncmd2: %s\n", info->out_cmd[0], info->out_cmd[1]);//erase
	printf("path1: %s\npath2: %s\n", info->path1, info->path2);//erase
	printf("cmd1: %s\ncmd1: %s\n", info->in_cmd[0], info->in_cmd[1]);//erase
//	printf("in fd: %i\nout fd: %i\n", info->in_fd, info->out_fd);//erase
	if (pipe(fd) < 0)
		print_error("pipe", 0, info);
	//exit (1);
	pid = fork(); //fork();
	if (pid < 0)
	{
		//printf("I'm in the fork pid %d\n", pid); //erase
		print_error("fork", 0, info);
		exit (1);
	}
	if (pid == 0)
		child_process(envp, argv[1], info, fd);
	else
		parent_process(envp, argv[4], info, fd);
	waitpid(pid, NULL, 0);
//	printf("after all: %i\n", 1);//erase
//	clean_up(info);
	return (0);
}
