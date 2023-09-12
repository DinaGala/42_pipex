/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:46:26 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/03 15:50:48 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_tolower(int ch)
{
	if ((ch > 64) && (ch < 91))
			ch = ch + 32;
	return (ch);
}

/*int	main(void)
{
	char	ch = 'A';

	printf("%c", ft_tolower(ch));
	return 0;
}*/
