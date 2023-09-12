/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:37:25 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/12 20:07:54 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*x;
	size_t	i;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, s1[0]))
		s1++;
	end = ft_strlen(s1);
	while (end && ft_strchr(set, s1[end - 1]))
		end--;
	x = (char *) malloc(end + 1);
	if (x == 0)
		return (NULL);
	i = 0;
	while (i < end)
	{
		x[i] = s1[i];
		i++;
	}
	x[i] = '\0';
	return (x);
}

/*int	main(void)
{
	char const	s1[] = "  \t \t \n   \n\n\n\t";
	char const	set[] = " \n\t";

	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
