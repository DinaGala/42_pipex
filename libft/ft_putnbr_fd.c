/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:51:28 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/13 22:25:27 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ln;

	ln = n;
	if (n < 0)
	{
		write (fd, "-", 1);
		ln = ln * -1;
	}
	if (ln < 10)
		ft_putchar_fd(ln + '0', fd);
	else
	{
		ft_putnbr_fd((ln / 10), fd);
		ft_putchar_fd((ln % 10 + '0'), fd);
	}
}

/*int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
//	ft_putnbr_fd(-9, 1);
	write (1, "\n", 1);
	return (0);
}*/
