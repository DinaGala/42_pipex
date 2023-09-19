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
	info -> in_cmd = NULL;
	info -> out_cmd = NULL;
}

void	clean_up(t_pipe *info)
{
	printf("I'm in the clean up %d\n", 1); //erase
	if (info && info->path1 != NULL)
		free(info->path1);
	printf("after path1 %d\n", 2); //erase
	if (info && info -> path2)
		free(info->path2);
	printf("after path2 %d\n", 3); //erase
	if (info && info -> in_cmd)
		ft_free(info -> in_cmd, -1);
	if (info && info -> out_cmd)
		ft_free(info -> out_cmd, -1);
	free(info);
	info = NULL;
}

char	*check_access(char **paths, char *cmd, t_pipe *info)
{
	char	*p;
	int		i;

	i = -1;

	while (paths[++i])
	{
		printf("check access, path %s\n", paths[i]); //erase
		p = ft_strjoin(paths[i], cmd);
		printf("check access, path+cmd %s\n", p); //erase
		if (!p)
		{
			ft_free(paths, -1);
			print_error("malloc", 0, info);
		}
		printf("check access, access F %i -- accessX %i\n", access(p, F_OK), access(p, X_OK)); //erase
		printf("check access, p is %s\n", p); //erase
		if (access(p, F_OK) == 0)
		{
			if(access(p, X_OK) != 0)
			{
				ft_free(paths, -1);
				print_error("access", 0, info);
			}
			else
			{
				printf("getting away from check access, path %s\n", paths[i]); //erase
				return (p);
			}
		}
	}
	return (NULL);
}
