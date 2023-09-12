/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:29:12 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/04 20:35:33 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

static size_t	count(char *str)
{
	size_t	lenth;

	lenth = 0;
	while (str[lenth])
		lenth++;
	return (lenth);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	d;
	size_t	s;
	size_t	j;

	d = count(dest);
	s = count((char *)src);
	i = 0;
	j = d;
	if (d >= size || size == 0)
		return (s + size);
	while (src[i] && i < size - d - 1)
	{
		dest[j] = src[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (s + d);
}

/*int	main(void)
{
	char	dest[20] = "";
	char    dest2[20] = "";
	char	src[20] = "";
	unsigned int	size = 0;

	printf("%s, %lu\n", dest2, strlcat(dest2, src, size));
	printf("%s, %u\n", dest, ft_strlcat(dest, src, size));
	return (0);
}*/
