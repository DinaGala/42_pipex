/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 17:15:04 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 18:27:40 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		s;
	size_t		f;

	if (*little == '\0')
		return ((char *)big);
	s = 0;
	while (big[s] && s < len)
	{
		f = 0;
		while (big[s + f] && big[s + f] == little[f] && (s + f) < len)
		{
			if (little[f + 1] == '\0')
				return ((char *)&big[s]);
			f++;
		}
		s++;
	}
	return (NULL);
}

/*int	main(void)
{
	const char	str[] = "hola me llamo actor comp";
	const char	to_find[] = "actor";
	size_t	len = 25;

	printf("%s\n", strnstr(str, to_find, len));
	printf("%s\n", ft_strnstr(str, to_find, len));
	return (0);
}*/
