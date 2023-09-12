/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:56:55 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 18:02:19 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*x;
	int		a;

	i = 0;
	a = 0;
	x = "\0";
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			x = (char *)&str[i];
			a++;
		}
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	else if (a > 0)
		return (x);
	return (NULL);
}

/*int	main(void)
{
	const char str[] = "http://www.tutorialspoint.com";
   	int c = 'z';

	printf("%s\n", strrchr(str, c));
	printf("%s\n", ft_strrchr(str, c));
	return (0);
}*/
