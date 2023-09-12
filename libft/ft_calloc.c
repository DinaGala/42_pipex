/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:13:31 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/05 16:03:58 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*mem;

	mem = malloc(nitems * size);
	if (mem == 0)
		return (0);
	ft_memset(mem, 0, nitems * size);
	return (mem);
}

/*int	main(void)
{
	size_t	nitems = 3;
	size_t	size = 4;
	size_t	i;
	int		*c;
	int		*f;

	c = (int *)calloc(nitems, size);
	f = (int *)ft_calloc(nitems, size);
	for( i=0 ; i < nitems ; i++ ) 
	{
		printf("%d ",c[i]);
    }	
	printf("\n");
	for( i=0 ; i < nitems ; i++ )
    {
        printf("%d ",f[i]);
    }
	return (0);
}*/
