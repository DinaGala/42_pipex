/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:04:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/17 16:26:10 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_split_path(t_pipe *info, char *s, char c, int i)
{
	char	**arr;
	int		n;
	int		start;

	n = -1;
	arr = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
//	printf("split path, path %s\n", s); //erase
//	printf("split path, count words %d\n", count_words(s, c)); //erase
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != c && i == 0)
			start = i;
		else if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
		//	printf("split path, string place %s\n", s + i); //erase
		//	printf("split path, start %i --- n %i\n", start, n);
			arr[++n] = ft_substr_path(s, start, (i - start + 1));
	//		printf("split path, part %s\n", arr[n]); //erase
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

char	**ft_split_cmd(t_pipe *info, char *s, char c, int i)
{
	char	**arr;
	int		n;
	int		start;

	n = -1;
//	printf("I'm in the split cmd %d\n", n); //erase
	arr = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != c && i == 0)
			start = i;
		else if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr(s, start, (i - start + 1));
//			printf("part: %s\n", arr[n]); //erase
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

char	**ft_split_quotes(t_pipe *info, char *s, char c, int i)
{
	char	**arr;
	int		n;
	int		start;
//	int		len;

	n = -1;
	arr = (char **) malloc((count_cmd(s, c) + 1) * sizeof(char *));
//	printf("I'm in the split quotes %d\n", count_cmd(s, c)); //erase
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != ' ' && i == 0)
			start = i;
		else if (s[i] != ' ' && s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
	//	else if // here add the quotes story
		if (s[i] != ' ' && (s[i + 1] == ' ' || !s[i + 1]))
		{
			arr[++n] = ft_substr(s, start, (i - start + 1));
	//		printf("part: %s\n", arr[n]); //erase
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
			start = i; // what to do with the start
		}
		else if (s[i] == ' ' && s[i + 1] == c)
		{
			start = ++i;
			while (s[i] && s[i + 1] != c)
				i++;
			arr[++n] = ft_substr(s, start, (i - start + 1));
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
			start = i;
		}
	}
	arr[++n] = NULL;
	return (arr);
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
