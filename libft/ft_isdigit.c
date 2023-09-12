/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:57:51 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/04 19:05:32 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isdigit(int x)
{
	if (x > 47 && x < 58)
		return (1);
	return (0);
}

/*int	main(void)
{
	char	x = 58;

	printf("%d\n", isdigit(x));
	printf("%d\n", ft_isdigit(x));
	return (0);
}*/
