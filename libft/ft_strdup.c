/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 18:02:14 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 16:01:55 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*m;
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	m = (char *) malloc(size);
	if (m == 0)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	return (m);
}

/*int	main(void)
{
	const char	s[] = "123456";

	printf("%s\n", ft_strdup(s));
	printf("%s\n", strdup(s));
	return (0);
}*/
