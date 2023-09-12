/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:53:24 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 17:49:46 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

/*int	main(void)
{
	const char str[] = "http://www.tutorialspoint.com";
   	int c = 't';

	printf("%s\n", strchr(str, c));
	printf("%s\n", ft_strchr(str, c));
	return (0);
}*/
