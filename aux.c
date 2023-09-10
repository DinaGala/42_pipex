/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:58:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/10 19:57:29 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

int	ft_strncmp(char *envp, char *path, int n)
{
	int			i;

	i = 0;
	if (n == 0) //do I need it in my case?
		return (0);
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n - 1)
			i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	**ft_split(t_pipe info, char *s, char c, int i)
{
	char	**arr;
	int		n;
	int		start;

	n = -1;
	arr = (char **) malloc((count(s, c) + 1) * sizeof(char *));
	if (arr == 0)
		print_error("Malloc error", 0, info);
	while (*s && s[++i])
	{
		if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[++n] = ft_substr(s, start, (i - start + 2));// i added + 2 to add the /
			if (arr[n] == 0)
				print_error("Malloc error", 0, info);
		}
	arr[++n] = NULL;
	return (arr);
}

int	count(char *s, char c)
{
	int		i;
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

char	*ft_substr(char *s, int start, int len)
{
	char	*m;
	int		i;

	i = 0;
	m = (char *) malloc(len + 2);
	if (m == 0)
		return (NULL);
	while (i < len && s[i + start])
	{
		m[i] = s[i + start];
		i++;
	}
	m[i] = '/';
	m[++i] = '\0';
	return (m);
}
