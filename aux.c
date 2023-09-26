/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:58:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/26 20:35:56 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

int	count_cmd(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != ' ' && (s[i + 1] == ' ' || !s[i + 1]))
			count++;
		else if (s[i] == ' ' && s[i + 1] == c)
		{
			i++;
			while (s[i] && s[i + 1] != c)
				i++;
			if (!s[i])
				return (count);
		}
		i++;
	}
	return (count);
}

char	**decision_maker(t_pipe *info, char *s, int i)
{
	char	first;

	first = '\0';
	while (s[++i])
	{
		if (!first && (s[i] == '\'' || s[i] == '\"'))
		{
			first = s[i];
			break ;
		}
	}
	if (!first)
		return (ft_split_cmd(info, s, -1, -1));
	else
		return (ft_split_quotes(info, s, first));
	return (NULL);
}

char	*ft_substr_path(char *s, int start, int len)
{
	char	*m;
	int		i;

	i = 0;
	m = (char *) malloc(len + 2);
	if (m == 0)
		return (NULL);
	while (i < len)
	{
		m[i] = s[i + start];
		i++;
	}
	m[i] = '/';
	m[i + 1] = '\0';
	return (m);
}

char	*ft_substr_slash(char *s, int start, int len, int i)
{
	char	*m;
	int		new_len;

	new_len = len;
	while (++i < (len - 1) && s[i + start + 1])
	{
		if (s[i + start] == '\\' && s[i + start + 1] == '\"')
			new_len--;
	}
	i = 0;
	m = (char *) malloc(new_len + 1);
	if (m == 0)
		return (NULL);
	while (i < new_len && s[i + start])
	{
		if (s[i + start] == '\\' && s[i + start + 1] == '\"')
			start++;
		else
		{
			m[i] = s[start + i];
			i++;
		}
	}
	m[i] = '\0';
	return (m);
}
