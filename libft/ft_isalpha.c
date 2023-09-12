/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:46:30 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/04 18:54:27 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

#include "libft.h"

int	ft_isalpha(int x)
{
	int	i;

	i = 0;
	if ((x > 64 && x < 91) || (x > 96 && x < 123))
		i = 1;
	return (i);
}

/*int	main(void)
{
	char	a = 'a';

	printf("%d\n", isalpha(a));
	printf("%d\n", ft_isalpha(a));
	return (0);
}*/
