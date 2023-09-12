/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:05:06 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/02 16:15:08 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>

int	ft_isprint(int x)
{
	if (x > 31 && x < 127)
		return (1);
	return (0);
}

/*int	main(void)
{	
	char	x = '\0';

	printf("%d\n", isprint(x));
	printf("%d\n", ft_isprint(x));
	return (0);
}*/
