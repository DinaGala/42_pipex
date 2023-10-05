/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:37:33 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/05 18:37:38 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	last_child(char *envp[], char *argv, t_pipe *info, char *outfile)
{
	char	*the_path;
	char	**cmd;

	the_path = NULL;
	cmd = decision_maker(info, argv, -1);
	info -> out_fd = open(outfile, O_TRUNC | O_CREAT | O_RDWR, 0666);
	if (info -> out_fd == -1)
		print_error(outfile, 0, info);
	if (dup2(info->out_fd, STDOUT_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(info->out_fd);
	if (dup2(info->in_fd, STDIN_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(info->in_fd);
	check_access(info, cmd, &the_path);
	if (execve(the_path, cmd, envp) < 0)
		print_error(cmd[0], 0, info);
}

void	child_process(char *envp[], char *argv, t_pipe *info, char *infile)
{
	char	**cmd;
	char	*the_path;

	the_path = NULL;
	close(info->fd[0]);
	cmd = decision_maker(info, argv, -1);
	if (info -> in_fd == -1)
		info -> in_fd = open(infile, O_RDONLY);
	if (info -> in_fd == -1)
		print_error(infile, 0, info);
	if (dup2(info->in_fd, STDIN_FILENO) < 0)
		print_error("dup2 file descriptor", 0, info);
	close(info->in_fd);
	if (dup2(info->fd[1], STDOUT_FILENO) < 0)
		print_error("dub2 file descriptor", 0, info);
	close(info->fd[1]);
	check_access(info, cmd, &the_path);
	if (execve(the_path, cmd, envp) == -1)
		print_error(cmd[0], 0, info);
}

void	pipex(int argc, char **argv, char *envp[], t_pipe *info)
{
	while (++info->m < argc - 1)
	{
		if (info->m < argc - 2)
			pipe(info -> fd);
		if (info->fd < 0)
			print_error("pipe", 0, info);
		info->pid = fork();
		if (info->pid < 0)
			print_error("fork", 0, info);
		else if (info->pid == 0 && info->m < argc - 2)
			child_process(envp, argv[info->m], info, argv[1]);
		else if (info->pid == 0 && info->m == argc - 2)
			last_child(envp, argv[info->m], info, argv[info->m + 1]);
		close (info->fd[1]);
		close (info->in_fd);
		info->in_fd = info->fd[0];
	}
	while (++info->j < argc - 1)
	{
		if (waitpid(-1, &info->status, 0) == info->pid)
			info->exit_status = WEXITSTATUS(info->status);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*info;

	info = NULL;
	if (argc < 5)
		print_error("invalid arguments: Introduce at least \
			   	4 arguments\n", 22, info);
	info = malloc(sizeof(t_pipe));
	if (!info)
		print_error("malloc", 0, NULL);
	initialize_tpipe(info, envp, argv);
	pipex(argc, argv, envp, info);
	clean_up(info);
	return (info->exit_status);
}
