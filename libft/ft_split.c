/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:34:04 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/13 22:24:24 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static char	**totalfree(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static size_t	count(char const *s, char c)
{
	int		i;
	size_t	count;

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

char	**ft_pop(char const *s, char c, char **arr, size_t n)
{
	size_t	i;
	size_t	start;

	i = 0;
	while (s[i])
	{
		if (s[i] != c && i == 0)
			start = i;
		else if (s[i] != c && i > 0 && s[i - 1] == c)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			arr[n] = ft_substr(s, start, (i - start + 1));
			if (arr[n] == 0)
				return (totalfree(arr, n));
			n++;
		}
		i++;
	}
	arr[n] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	arr = (char **) malloc((count(s, c) + 1) * sizeof(char *));
	if (arr == 0)
		return (NULL);
	return (ft_pop(s, c, arr, 0));
}

/*int	main(void)
{
//	int			i;
	char 		**res;
	res = ft_split("tripouille", 0);
//	printf("res[0]: %s\n", res[0]);
//	printf("res[1]: %p", res[1]);
	
//	printf("%lu\n", count("tripouille", 0));	
//	for (i = 0; i < 2; i++)
//	{
//	  	printf("%s\n", ft_split("tripouille", 0)[i]);
//	}
//	printf("%d\n", strcmp(ft_split("tripouille", 0)[0], "tripouille"));
//	printf("%d\n", ft_split("tripouille", 0)[1] == NULL);
//	printf("%p\n", ft_split("tripouille", 0)[1]);
	return (0);
}*/
