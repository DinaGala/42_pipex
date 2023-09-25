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
	info -> paths = NULL;
	info -> path1 = NULL;
	info -> path2 = NULL;
	info -> in_cmd = NULL;
	info -> out_cmd = NULL;
}

void	clean_up(t_pipe *info)
{
//	printf("I'm in the clean up %d\n", 1); //erase
	if (info && info->path1 != NULL)
		free(info->path1);
//	printf("after path1 %d\n", 2); //erase
	if (info && info -> path2)
		free(info->path2);
//	printf("after path2 %d\n", 3); //erase
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

//	while (paths[++i])
//	{
//		printf("what s in the path %i -- %s\n", i, paths[i]); //erase
//	}
//	i = -1;
	while (paths[++i])
	{
	//	printf("check access, path %i -- %s\n", i, paths[i]); //erase
		p = ft_strjoin(paths[i], cmd);
	//	printf("check access, path+cmd %s\n", p); //erase
		if (!p)
		{
			ft_free(paths, -1);
			print_error("malloc", 0, info);
		}
	//	printf("check access, access F %i -- accessX %i\n", access(p, F_OK), access(p, X_OK)); //erase
	//	printf("check access, p is %s\n", p); //erase
		if (access(p, F_OK) == 0)
		{
			if(access(p, X_OK) != 0)
			{
				ft_free(paths, -1);
				print_error(strerror(126), 126, info);
			}
			else
			{
				//printf("getting away from check access, path %s\n", p); //erase
				return (p);
			}
		}
	}
//	printf("getting away from check access with NULL %s\n", NULL); //erase
	print_error(ft_strjoin(cmd, ": command not found\n"), 127, info);
	return (NULL);
}

/*void	trim_slashes(t_pipe info, int i)
{
//	int	j;

//	j = -1
	while (info->in_cmd[++i])
	{
//		while (info->in_cmd[i][++j])
//		{	
//			if(info->in_cmd[i][j] == '\\' && info->in_cmd[i][j + 1] == "\"")
		if (ft_strnstr(info->in_cmd[i], "\\\"", ft_strlen(info->in_cmd[i] + 1)))
			info->in_cmd[i] = ft_strtrim(info->in_cmd[i], "\\");
		if (!info->in_cmd[i])
			print_error("malloc", 0, info);
	}
	i = -1;
	while (info->out_cmd[++i])
	{
		if (ft_strnstr(info->out_cmd[i], "\\", ft_strlen(info->out_cmd[i] + 1)))
			info->out_cmd[i] = ft_strtrim(info->out_cmd[i], "\\");
		if (!info->out_cmd[i])
			print_error("malloc", 0, info);
	}
	i = -1;
}*/

char	*ft_substr_slash(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	i;
	size_t	new_len;

	new_len = len;
	i = 0;
//	printf("entering cut len is %zu\n", len); //erase
	while (i < (len - 1) && s[i + start + 1])
	{
		if (s[i + start] == '\\' && s[i + start + 1] == '\"')
			new_len--;
		i++;
	}
	i = 0;
//	printf("new_len is  %zu\n", new_len); //erase
	m = (char *) malloc(new_len + 1);
	if (m == 0)
		return (NULL);
	while (i < new_len && s[i + start])
	{
		if (s[i + start] == '\\' && s[i + start + 1] == '\"')
			start++;
		else
		{
			m[i] = s[i + start];
	//		printf("i copy the  %c\n", s[i + start]);
			i++;
		}
	}
	m[i] = '\0';
//	printf("lenth of final substr %zu\n", ft_strlen(m));
	return (m);
}