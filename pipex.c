/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 19:29:07 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/08 21:23:06 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"




void	fill_t_pipe(char **argv, t_pipe *info, char *envp[], int i)
{
	initialize_tpipe(info);
	info -> in_fd = open(argv[1], O_RDONLY);
	if (info -> in_fd == -1)
		print_error("Input file descriptor", 0, info);
	info -> out_fd = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (info -> out_fd == -1)
		print_error("Output file descriptor", 0, info);
	while (envp[++i])
	{
		if (ft_strcmp(envp[i], "PATH=", 5) == 0)
		{
			info -> paths = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
/*	if (!info->paths) // do I need it?
		info -> paths = ft_split("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:", ':');*/
	info -> in_args = argv[2];
	info -> out_args = argv[3];
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*info;
	
	info = malloc(sizeof(t_pipe));
	if (!info)
		print_error("Malloc error", 0, NULL);
	if (argc != 5)
		 print_error("Arguments error: Wrong amount of arguments\n", 1, info); //check if it works
	fill_t_pipe(argv, info, envp, -1);
	//here the pipe, dup2 and fork stuff starts

}
