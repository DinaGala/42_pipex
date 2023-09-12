/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 18:29:35 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 19:48:33 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*str1;

	str1 = (char *)str;
	while (n--)
	{	
		if (*str1 == (char)c)
			return ((void *)str1);
		str1++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char str[] = "http://www.tutorialspoint.com";
   	int c = 'i';
	size_t	n = 4;

	printf("%s\n", memchr(str, c, n));
	printf("%s\n", ft_memchr(str, c, n));
	return (0);
}*/
