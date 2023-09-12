/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:54:24 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/08 19:29:52 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	i;
	size_t	count;

	count = ft_strlen(s);
	i = 0;
	if (start > count)
		len = 0;
	else if (count - start < len)
		len = count - start;
	m = (char *) malloc(len + 1);
	if (m == 0)
		return (NULL);
	while (i < len && s[i])
	{
		m[i] = s[i + start];
		i++;
	}
	m[i] = '\0';
	return (m);
}

/*int   main(void)
{
    const char  s[] = "123456";

    printf("%s\n", ft_substr(s, 10, 6));
    return (0);
}*/
