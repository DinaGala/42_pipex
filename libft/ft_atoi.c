/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:46:05 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/09 17:35:10 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	min;
	int	x;

	i = 0;
	min = 1;
	x = 0;
	while (((str[i] > 8 && str[i] < 14) || str[i] == 32) && str[i])
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			min = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58 && str[i])
	{
		x = x * 10 + (str[i] - 48);
		i++;
	}
	return (min * x);
}

/*int	main(void)
{
	char	str[] = " -2147483647";

	printf("%i\n", atoi(str));
	printf("%i", ft_atoi(str));
	return (0);
}*/
