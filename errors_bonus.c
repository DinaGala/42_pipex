/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:06:53 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/14 17:34:12 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_error(char *message, int flag, t_pipe *info)
{
	if (info)
		clean_up(info);
	write(2, "pipex: ", 7);
	if (flag == 0)
		perror(message);
	else
	{
		write(2, message, ft_strlen(message));
		exit(flag);
	}
	exit(errno);
}

void	clean_up(t_pipe *info)
{
//	printf("after path2 %d\n", 3); //erase
	if (info && info -> paths)
		ft_free(info -> paths, -1);
	if (info && info -> str_doc)
		free(info -> str_doc);
//	if (info -> in_fd > 0)
//		close(info->in_fd);
//	if (info -> out_fd > 0)
//		close(info->out_fd);
//	if (info -> fd[0] > 0)
//		close(info->fd[0] > 0);
//	if (info -> fd[1])
//		close(info->fd[1]);
	free(info);
	info = NULL;
}

void	ft_free(char **arr, int n)
{
	while (n > 0)
		free(arr[n--]);
	if (n == 0)
		free(arr[n]);
	if (n < 0)
	{
		while (arr[++n])
			free(arr[n]);
	}
	free(arr);
	arr = NULL;
}

void	check_access(t_pipe *info, char **cmd, char **path)
{
//	printf("entering checking path: %s\n", *path); //erase
//	first checking the scripts
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], F_OK) == 0)
		{
			if(access(cmd[0], X_OK) != 0)
				print_error(ft_strjoin(cmd[0], ": Permission denied"), 126, info);
			*path = ft_strdup(cmd[0]);
		}
		else
			print_error(ft_strjoin(cmd[0], ": command not found\n"), 127, info);
	}
	else
		*path = ft_strdup(check_paths(info->paths, cmd[0], info));
}

char	*check_paths(char **paths, char *cmd, t_pipe *info)
{
	char	*p;
	int		i;

	i = -1;
	while (paths[++i])
	{
		p = ft_strjoin(paths[i], cmd);
		if (!p)
		{
			ft_free(paths, -1);
			print_error("malloc", 0, info);
		}
		if (access(p, F_OK) == 0)
		{
			if(access(p, X_OK) != 0)
				print_error(ft_strjoin(cmd, ": Permission denied"), 126, info);
			else
				return (p);
		}
	}
	print_error(ft_strjoin(cmd, ": command not found\n"), 127, info);
	return (NULL);
}
