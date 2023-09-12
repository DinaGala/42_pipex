/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 21:56:58 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/05/14 22:39:36 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*i;
	t_list	*head;
	void	*t;

	head = NULL;
	while (lst)
	{
		t = f(lst->content);
		i = ft_lstnew(t);
		if (!i)
		{
			ft_lstclear(&head, del);
			del(t);
			return (NULL);
		}
		ft_lstadd_back(&head, i);
		lst = lst->next;
	}
	return (head);
}
