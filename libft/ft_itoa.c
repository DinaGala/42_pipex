/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:29:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/10 21:33:14 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	lenth(long n)
{
	long	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*x;
	int		len;
	long	ln;

	ln = n;
	len = lenth(ln);
	x = (char *) malloc(len + 1);
	if (x == 0)
		return (NULL);
	x[len] = '\0';
	if (ln < 0)
	{
		x[0] = '-';
		ln = ln * -1;
	}
	else if (ln == 0)
		x[0] = '0';
	while (ln > 0)
	{
		x[len - 1] = ln % 10 + 48;
		ln = ln / 10;
		len--;
	}
	return (x);
}

/*int	main(void)
{
	int	n = 0;

	printf("%s\n", ft_itoa(n));
	return (0);
}*/
