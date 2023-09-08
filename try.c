/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:20:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/08 19:49:18 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(void)
{
	perror("Error");
}

int	main(int argc, char **argv)
{
//	char	*err;
//	int	fd;

	//err = strerror(12);
//	fd = open("text", O_RDONLY);
//	if (!fd)
//		perror("Error");
	if (argc < 2)
		return (write(2, "Arguments error: Wrong amount of arguments\n", 43));
//	err = malloc(3);
//	print_error();
//	printf("%s\n", strerror(12));
	return (0);
}
