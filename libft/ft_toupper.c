/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:37:32 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/03 15:44:50 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_toupper(int ch)
{
	if ((ch > 96) && (ch < 123))
			ch = ch - 32;
	return (ch);
}

/*int	main(void)
{
	char	ch = 'Y';

	printf("%c", ft_toupper(ch));
	return 0;
}*/
