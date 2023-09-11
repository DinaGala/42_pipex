/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 22:04:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/11 22:12:25 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.c"

char	**ft_split_path(t_pipe info, char *s, char c, int i)
{
	char	**arr;
	int		n;
	int		start;

	n = -1;
	arr = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr(s, start, (i - start + 2), 0);// i added + 2 to add the /
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
		}
	arr[++n] = NULL;
	return (arr);
}

char	**ft_split_cmd(t_pipe info, char *s, int i)
{
	char	**arr;
	int		n;
	int		start;

	n = -1;
	arr = (char **) malloc((count_cmd(s) + 1) * sizeof(char *));
	if (arr == 0)
		print_error("malloc", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr(s, start, (i - start + 1), 1);
			if (!arr[n] && n > 0)
			{
				ft_free(arr, n);
				print_error("malloc", 0, info);
			}
		}
	arr[++n] = NULL;
	return (arr);
}

int	count_cmd(char *s)
{
