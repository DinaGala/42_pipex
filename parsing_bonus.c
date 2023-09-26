/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:04:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/26 20:33:55 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**ft_split_path(t_pipe *info, char *s, int n, int i)
{
	char	**arr;
	int		start;

	arr = (char **) malloc((count_words(s, ':') + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != ':' && i == 0)
			start = i;
		else if (s[i] != ':' && i > 0 && s[i - 1] == ':')
			start = i;
		if (s[i] != ':' && (s[i + 1] == ':' || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr_path(s, start, (i - start + 1));
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
		}
	}
	arr[++n] = NULL;
	return (arr);
}

char	**ft_split_cmd(t_pipe *info, char *s, int n, int i)
{
	char	**arr;
	int		start;

	arr = (char **) malloc((count_words(s, ' ') + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != ' ' && i == 0)
			start = i;
		else if (s[i] != ' ' && i > 0 && s[i - 1] == ' ')
			start = i;
		if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr(s, start, (i - start + 1));
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
		}
	}
	arr[++n] = NULL;
	return (arr);
}

char	**ft_split_quotes(t_pipe *info, char *s, char c)
{
	char	**arr;

	info -> n = -1;
	info -> i = -1;
	arr = (char **) malloc((count_cmd(s, c) + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	info -> flag = 0;
	return (ft_pop_quotes(info, s, c, arr));
}

char	**ft_pop_quotes(t_pipe *info, char *s, char c, char **arr)
{
	while (*s && s[++info->i])
	{
		ft_start_quotes(info, s, c);
		if ((s[info->i] != ' ' && (s[info->i + 1] == ' ' || !s[info->i + 1]) \
					&& info->flag == 0) || (s[info->i] == c \
						&& (s[info->i + 1] == ' ' || !s[info->i + 1]) && \
						info->flag == 1 && s[info->i - 1] != '\\'))
		{
			if (info->flag == 1)
				arr[++info->n] = ft_substr_slash(s, info->start, \
						(info->i - info->start), -1);
			else
				arr[++info->n] = ft_substr_slash(s, info->start, \
						(info->i - info->start + 1), -1);
			if (!arr[info->n] && info->n > 0)
			{
				ft_free(arr, info->n);
				print_error("malloc", 0, info);
			}
			if (info->flag == 1)
				info->flag = 0;
		}
	}
	arr[++info->n] = NULL;
	return (arr);
}

void	ft_start_quotes(t_pipe *info, char *s, char c)
{
	if ((s[info->i] == c && info->i == 0) || \
		(s[info->i] == c && s[info->i - 1] == ' ' && info->flag == 0 && \
		info->i > 0))
	{
		info->flag = 1;
		info->start = info->i + 1;
	}
	else if (info->i == 0 && s[info->i] != ' ')
		info->start = info->i;
	else if (s[info->i] != ' ' && !info->flag && info->i > 0 && \
			s[info->i - 1] == ' ')
		info->start = info->i;
}
