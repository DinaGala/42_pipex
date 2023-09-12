/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:33:17 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/08 19:55:55 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		count1;
	size_t		count2;
	char		*s;

	count1 = ft_strlen(s1);
	count2 = ft_strlen(s2);
	i = 0;
	s = (char *) malloc(count1 + count2 + 1);
	if (s == 0)
		return (NULL);
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[i + count1] = s2[i];
		i++;
	}
	s[count1 + count2] = '\0';
	return (s);
}

/*int	main(void)
{
	const char  s1[] = "123456";
	const char	s2[] = "789";

    printf("%s\n", ft_strjoin(s1, s2));
    return (0);
}*/
