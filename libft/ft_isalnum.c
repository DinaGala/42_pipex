/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:36:22 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/04 19:04:58 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isalnum(int x)
{
	if ((x > 47 && x < 58) || (x > 64 && x < 91) || (x > 96 && x < 123))
		return (1);
	return (0);
}

/*int	main(void)
{
	int	x = 116;

	printf("%d\n", isalnum(x));
	printf("%d\n", ft_isalnum(x));
	return (0);
}*/
