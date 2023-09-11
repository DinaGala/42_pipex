/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:20:20 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/09/11 20:25:04 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(errno);
}

int	main(int argc, char **argv)
{
//	char	*err;
	int	fd;

	fd = open("text", O_RDONLY);
//	if (!fd)
//	perror("Error");
//	if (argc < 2)
//		return (write(2, "Arguments error: Wrong amount of arguments\n", 43));
//	err = malloc(3);
	rror();
//	printf("%s\n", strerror(12));
	return (0);
}
