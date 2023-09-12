/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:08:33 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/14 18:41:33 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew;

	lstnew = (t_list *) malloc(sizeof(t_list));
	if (lstnew == 0)
		return (NULL);
	lstnew -> content = content;
	lstnew -> next = NULL;
	return (lstnew);
}

/*#include <stdio.h>

int	main(void)
{
	char	*c = "123";
	t_list	*cont;

	cont = ft_lstnew((void *)c);
	printf("%s\n", (char *)cont->content);
	printf("%s\n", (char *)cont->next);
	return (0);
}*/
