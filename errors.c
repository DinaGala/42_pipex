/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:06:53 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/10 19:57:26 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *message, int flag, t_pipe *info)
{
	if (flag == 0)
		perror(message);
	else
		write(2, message, ft_strlen(s));
	if (info)
		clean_up(info);
	exit(1);
}

void	initialize_tpipe(t_pipe *info)
{
	info -> in_fd = -1;
	info -> out_fd = -1;
	info -> paths = NULL;
	info -> in_args = NULL;
	info -> out_args = NULL;
}

void	clean_up(t_pipe *info)
{
	int	i;

	i = -1;
	if (!info)
		return ;
	if (info -> paths)
	{
		while (info->paths[++i])
			free(info->paths[i]);
		free(info->paths);
		info->paths = NULL;
	}
	if (info->in_args) //not sure I will allocate it
		free(info->in_args);
	if (info->out_args)
		free(info->out_args);
	info->in_args = NULL;
	info->out_args = NULL;
}

char	*ft_trim(char *cmd)
{

