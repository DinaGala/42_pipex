/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:38:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/26 20:48:49 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include "./libft/libft.h"

# define DEF "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/go/bin:"

typedef struct s_struct
{
	int		i;
	int		n;
	int		flag;
	int		start;
	int		j;
	int		status;
	int		here_doc;
	char	*str_doc;
	int		in_fd;
	int		out_fd;
	int		fd[2];
	char	**paths;
//	char	**cmds;
//	char	*path1;
//	char	*path2;
//	char	**in_cmd;
//	char	**out_cmd;
}	t_pipe;

/***** pipex_bonus.c - main, pipex and child/parent processes *****/
// main
//void	parse_all(char **argv, t_pipe *info, char *envp[], int i);
void	initialize_tpipe(t_pipe *info, char *envp[], char **argv);
void	ft_here_doc(t_pipe *info, char **argv);
void	last_child_process(char *envp[], char *argv, t_pipe *info, char *outfile);
void	child_process(char *envp[], char *argv, t_pipe *info, char *infile);
/********************************/

/***** aux_bonus.c - functions that are helping to split */
char	**decision_maker(t_pipe *info, char *s, int i);
int		count_words(char *s, char c);
int		count_cmd(char *s, char c);
char	*ft_substr_slash(char *s, int start, int len, int i);
char	*ft_substr_path(char *s, int start, int len);
/********************************/

/***** errors_bonus.c - functions that check the access, clean up and print error */
void	print_error(char *message, int flag, t_pipe *info);
void	ft_free(char **arr, int n);
void	clean_up(t_pipe *info);
void	check_access(t_pipe *info, char **cmd, char **path);
char	*check_paths(char **paths, char *cmd, t_pipe *info);
/********************************/

/***** parsing_bonus.c - slightly different versions of split for different cases */
char	**ft_split_path(t_pipe *info, char *s, int n, int i);
char	**ft_split_cmd(t_pipe *info, char *s, int n, int i);
char	**ft_split_quotes(t_pipe *info, char *s, char c);
char	**ft_pop_quotes(t_pipe *info, char *s, char c, char **arr);
void	ft_start_quotes(t_pipe *info, char *s, char c);
/********************************/

#endif
