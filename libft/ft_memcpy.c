/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:39:21 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 19:21:13 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest1;
	unsigned const char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned const char *)src;
	if (!dest1 && !src1)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char	dest[] = "1234567890";
	char	dest0[] = "1234567890";
//	char	*x;
	//char	src[] = "";
	size_t	n = 7;

//	x = memcpy(dest0 + 2, dest0, n);
	printf("%s\n", memcpy(dest0 + 2, dest0, n));
//	printf("%c\n", x[2]);
	printf("%s\n", ft_memcpy(dest + 2, dest, n));
	return (0);
}*/
