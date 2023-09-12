/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:23:57 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/04 20:56:48 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	lenth;
	size_t	i;

	lenth = 0;
	while (src[lenth] != '\0')
		lenth++;
	i = 0;
	if (size != 0)
	{	
		while (src[i] && i < size - 1)
		{
		dest[i] = src[i];
		i++;
		}
		dest[i] = '\0';
	}
	return (lenth);
}

/*int	main(void)
{
	char	dest1[] = "de";
	char    dest2[] = "de";
	char    src[] = "";
	unsigned int	size = 0;

	printf("%lu\n", strlcpy(dest1, src, size));
	printf("%s\n", dest1);
	printf("%u\n", ft_strlcpy(dest2, src, size));
	printf("%s\n", dest2);
}*/
