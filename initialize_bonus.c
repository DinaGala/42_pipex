/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:19:25 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/10/05 18:35:06 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	initialize_tpipe(t_pipe *info, char *envp[], char **argv)
{
	info -> i = 0;
	info -> n = -1;
	info -> flag = 0;
	info -> here_doc = 0;
	info -> str_doc = NULL;
	while (envp[info->i] && ft_strncmp(envp[info->i], "PATH=", 5))
		info->i++;
	if (envp[info->i] && ft_strncmp(envp[info->i], "PATH=", 5) == 0)
		info -> paths = ft_split_path(info, envp[info->i] + 5, -1, -1);
	else
		info->paths = ft_split_path(info, DEF, -1, -1);
	info -> i = -1;
	info -> in_fd = -1;
	if (!ft_strncmp(argv[1], "here_doc\0", ft_strlen(argv[1])))
		info -> here_doc = 1;
	if (info -> here_doc)
		ft_here_doc(info, argv);
	info -> out_fd = -1;
	info->m = 1;
	if (info -> here_doc)
		info->m = 2;
	info->j = info->m;
}

void	ft_here_doc(t_pipe *info, char **argv)
{
	int	hd[2];

	if (pipe(hd) < -1)
		print_error("pipe", 0, info);
	while (42)
	{
		write(1, "> ", 2);
		info -> str_doc = get_next_line(0);
		if (!info -> str_doc)
			print_error("get_next_line", 0, NULL);
		else if (!ft_strncmp(info -> str_doc, argv[2], \
					ft_strlen(info -> str_doc) - 1) && \
				(ft_strncmp(info -> str_doc, "\n", 1)))
			break ;
		else if (!ft_strncmp(info -> str_doc, "\n", 1) && (*argv[2] == '\0'))
			break ;
		write(hd[1], info -> str_doc, ft_strlen(info->str_doc));
		free(info -> str_doc);
		info -> str_doc = NULL;
	}
	if (info -> str_doc)
		free(info -> str_doc);
	info -> str_doc = NULL;
	close(hd[1]);
	info -> in_fd = hd[0];
}
