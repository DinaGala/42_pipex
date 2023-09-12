/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:28:35 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/14 20:24:50 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

/*int	main(void)
{
	t_list	*c = "123";
	t_list	*begin = NULL;
	t_list	*cont;

	cont = ft_lstadd_back(begin, c);
	printf("%s\n", (char *)cont->content);
	printf("%s\n", (char *)cont->next);
	return (0);
}*/
