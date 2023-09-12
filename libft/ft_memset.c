/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:16:27 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 19:35:52 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*str1;

	str1 = (char *)str;
	i = 0;
	while (i < n)
	{
		str1[i] = c;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "1234567890";
	char	str0[] = "1234567890";
	int	c = 48;
	size_t	n = 12;

	printf("%s\n", memset(str0, c, n));
	printf("%s\n", ft_memset(str, c, n));
	return (0);
}*/
