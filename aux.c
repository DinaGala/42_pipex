/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:58:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/11 22:48:02 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*int	ft_strncmp_pipe(char *envp, char *path, int n)
{
	int			i;

	i = 0;
	if (n == 0) //do I need it in my case?
		return (0);
	while ((s1[i] && s2[i]) && s1[i] == s2[i] && i < n - 1)
			i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}*/

int	count_words(char *s, char c)
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

char	*ft_substr_pipe(char *s, int start, int len, int flag)
{
	char	*m;
	int		i;

	i = 0;
	m = (char *) malloc(len + 1);
	if (m == 0)
		return (NULL);
	while (i < len && s[i + start])
	{
		m[i] =s[i + start];
		i++;
	}
	if (flag == 0)
	{	
		m[i] = '/';
		i++;
	}
	m[i] = '\0';
	return (m);
}

void	ft_free(char **arr, int n)
{
	while (n > 0)
		free(arr[n--]);
	if (n == 0)
		free(arr[n]);
	if (n < 0)
	{
		while (arr[++n])
			free(arr[n]);
	}
	free(arr);
	arr = NULL;
}
