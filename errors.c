/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:06:53 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/26 21:39:14 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (info && info->path1 != NULL)
		free(info->path1);
	if (info && info -> path2)
		free(info->path2);
	if (info && info -> paths)
		ft_free(info -> paths, -1);
	if (info && info -> in_cmd)
		ft_free(info -> in_cmd, -1);
	if (info && info -> out_cmd)
		ft_free(info -> out_cmd, -1);
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
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], F_OK) == 0)
		{
			if (access(cmd[0], X_OK) != 0)
				print_error(ft_strjoin(cmd[0], ": Permission denied"), \
						126, info);
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
			if (access(p, X_OK) != 0)
				print_error(ft_strjoin(cmd, ": Permission denied"), 126, info);
			else
				return (p);
		}
	}
	print_error(ft_strjoin(cmd, ": command not found\n"), 127, info);
	return (NULL);
}
