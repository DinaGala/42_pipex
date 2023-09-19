/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 19:58:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/14 17:39:58 by nzhuzhle         ###   ########.fr       */
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

char	*ft_substr_path(char *s, int start, int len)
{
	char	*m;
	int		i;
//	int		count;

	i = 0;
//	count = ft_strlen(s);
//	if (start > count)
//		len = 0;
//	else if (count - start < len)
//		len = count - start;
	m = (char *) malloc(len + 2);
	if (m == 0)
		return (NULL);
//	printf("substring path, len %i\n", len);// erase
	while (i < len)
	{
		m[i] = s[i + start];
//		printf("substring path, mi %c\n", m[i]); //erase
		i++;
	}
//	printf("substring path, m %s\n", m); //erase
	m[i] = '/';
	m[i + 1] = '\0';
//	printf("substring path, m %s\n", m); //erase
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

char	**decision_maker(t_pipe *info, char *s, int i)
{
	int	sing;
	int	doub;
	char	first; // if it is 0 - no quotes, 1 - single is first, 2 - double, -1 - there are unclosed quotes

	first = '\0';
	sing = 0;
	doub = 0;
	while (s[++i])
	{
		if ((s[i] == '\'' && i == 0) || (s[i] == '\'' && s[i + 1] == ' ') || \
		(s[i] == '\'' && s[i - 1] == ' '))
			sing++;
		if ((s[i] == '\"' && i == 0) || (s[i] == '\"' && s[i + 1] == ' ') || \
		(s[i] == '\"' && s[i - 1] == ' '))
			doub++;
		if (!first && (s[i] == '\'' || s[i] == '\"'))
				first = s[i];
	}
	if ((doub % 2) != 0 || (sing % 2) != 0)
		print_error("non terminated string", 2, info);
	else if (!first)
		return (ft_split_cmd(info, s, ' ', -1));
	else
		return (ft_split_quotes(info, s, first, -1)); //return (ft_split_quotes(info, s, first, -1));
	return (NULL);
}
