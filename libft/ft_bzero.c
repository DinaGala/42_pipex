/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:25:55 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 19:35:22 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <strings.h>
//#include <stdio.h>

#include "libft.h"

void	ft_bzero(void *dst, size_t n)
{
	size_t		i;
	char		*dst1;

	dst1 = (char *)dst;
	i = 0;
	while (i < n)
	{
		dst1[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char	dst[] = "1234567890";
	char	dst0[] = "1234567890";
	size_t	n = 3;

	bzero(dst0, n);
	ft_bzero(dst, n);
	printf("%c\n", dst0[2]);
	printf("%c\n", dst[2]);
	return (0);
}*/
