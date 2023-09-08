/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:58:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/08 21:23:18 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	write(2, s, ft_strlen(s));
}

void	print_error(char *message, int flag, t_pipe *info)
{
	if (flag == 0)
		perror(message);
	else
		ft_putstr(message);
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

