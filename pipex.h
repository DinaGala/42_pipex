/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:38:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/10 19:57:20 by nzhuzhle         ###   ########.fr       */
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

# define DEFPATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki"

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
// child_process
// parent_process

/***** aux.c - */
int ft_strlen(char *s);
int	ft_strcmp(char *envp, char *path, int len); 
char	**ft_split(t_pipe info, char *s, char c, int i);
int count(char *s, char c);
char    *ft_substr(char *s, int start, int len);
/********************************/

/***** errors.c - */
int print_error(char *message, int flag, t_pipe *info); //- function that uses perror to display error message and type, or (if flag is 1) write for indefined errors, cleans info if needed. returns (1) - error exit for main
void    initialize_tpipe(t_pipe *info);
void    clean_up(t_pipe *info); // check if i should allocate the cmd
//char	*ft_trim(char *cmd); //trims \ " ' 

#endif
