/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:06:53 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/11 23:09:28 by nzhuzhle         ###   ########.fr       */
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

void	initialize_tpipe(t_pipe *info)
{
	info -> in_fd = -1;
	info -> out_fd = -1;
	info -> path1 = NULL;
	info -> path2 = NULL;
	info -> in_args = NULL;
	info -> out_args = NULL;
}

void	clean_up(t_pipe *info)
{
	if (info && info -> path1)
		free(info->path1);
	if (info && info -> path2)
		free(info->path2);
	if (info && info -> in_cmd)
		ft_free(info -> in_cmd, -1);
	if (info && info -> out_cmd)
		ft_free(info -> out_cmd, -1);
	free(info);
	info = NULL;
}

char	*check_access(char **paths, char *cmd)
{
	char	*p;
	int		i;

	i = -1;
	while (paths[++i] || !(*thepath))
	{
		p = strjoin(paths[i], cmd);
		if (!p)
		{
			ft_free(paths, -1);
			print_error("malloc", 0, info);
		}
		if (access(p, F_OK) == 0)
		{
			if(access(p, X_OK) != 0)
			{
				ft_free(paths, -1);
				print_error("access", 0, info);
			}
			else
				return (paths[i]);
		}
	}
	return (NULL);
}
