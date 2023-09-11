/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:38:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/11 23:09:24 by nzhuzhle         ###   ########.fr       */
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
# include <errno.h>

# define DEFPATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:/usr/local/munki"

typedef struct s_struct
{
	int     in_fd;
	int     out_fd;
//	char	**paths;
	char	*path1;
	char	*path2;
	char	**in_cmd;
	char	**out_cmd;
} t_pipe;

/***** pipex.c - main, pipex and child/parent processes *****/
// main
void	parse_all(char **argv, t_pipe *info, char *envp[], int i);// - i is a counter. 
void	check_paths(t_pipe *info, char **paths); //USES STRJOIN, strchr compile with libft. checks the scripts
void	parent_process(char *envp[], t_pipe *info, int fd[]);
void    child_process(char *envp[], t_pipe *info, int fd[]);

/***** aux.c - */
int ft_strlen(char *s);
int	ft_strcmp(char *envp, char *path, int len); 
int count_words(char *s, char c);
char    *ft_substr(char *s, int start, int len, int flag); // flag is 0 - I add / in the end of the path
void    ft_free(char **arr, int n); //if n= -1 - i free until NULL
/********************************/

/***** errors.c - */
int print_error(char *message, int flag, t_pipe *info); //- function that uses perror to display error message and type, or (if flag is 1) write for indefined errors, cleans info if needed. returns (1) - error exit for main
void    initialize_tpipe(t_pipe *info);
void    clean_up(t_pipe *info); // check if i should allocate the cmd
char	*check_access(char **paths, char *cmd) //USES STRJOIN, strchr compile with libft

//char	*ft_trim(char *cmd); //trims \ " ' 


/***** parsing.c - */
char    **ft_split_path(t_pipe info, char *s, char c, int i);
char    **ft_split_cmd(t_pipe info, char *s, char c, int i); // change it add all the quotes hell
//int count_cmd(char *s);

#endif
