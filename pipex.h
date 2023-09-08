/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:38:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/08 21:21:38 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h> //erase!!

# define DEFPATH "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:."

typedef struct s_struct
{
	int     in_fd;
	int     out_fd;
	char	**paths;
	char	*in_args;
	char	*out_args;
} t_pipe;

/***** pipex.c - main, pipex and child/parent processes *****/
// main
void	fill_t_pipe(char **argv, t_pipe *info, char *envp[], int i);// - i is a counter. 

/***** aux.c - */
int print_error(char *message, int flag, t_pipe *info); //- function that uses perror to display error message and type, or (if flag is 1) write for indefined errors, cleans info if needed. returns (1) - error exit for main
void    ft_putstr(char *s);
int ft_strlen(char *s);
void    initialize_tpipe(t_pipe *info);
//int	ft_strcmp(char *envp, char *path, int len); 
//ft_split(char *str, char delim);



#endif
