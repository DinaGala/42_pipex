/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:30:44 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/16 19:45:38 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char		*str11;
	const char	*str22;

	str11 = (char *)str1;
	str22 = (char *)str2;
	if (!str22 && !str11)
		return (NULL);
	if (str11 < str22)
		str1 = ft_memcpy(str1, str2, n);
	if (str22 < str11)
	{
		while (n--)
			str11[n] = str22[n];
	}
	return (str1);
}

/*int	main(void)
{
	char	dest[] = "1234567890";
	char	dest0[] = "1234567890";
	char	*y;
	char	*x;
//	char	src[] = "0000";
	size_t	n = 5;

	x = memmove(dest0, dest + 2, n);
	printf("%s\n", x);
	printf("%c\n", x[3]);
	y = ft_memmove(dest, dest + 2, n);
	printf("%s\n", y);
	printf("%c\n", y[3]);
	return (0);
}*/
