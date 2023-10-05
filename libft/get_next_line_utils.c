/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:35:28 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/06/15 18:17:19 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_line(t_list *node, long *lenth)
{
	long	i;

	i = 0;
	if (!node)
		return (0);
	while (node->content[i] && node->content[i] != '\n')
		i++;
	if (node->content[i] == '\n')
	{
		*lenth += ++i;
		return (1);
	}
	*lenth += i;
	return (0);
}

t_list	*last_node(t_list *node)
{
	if (!node)
		return (node);
	while (node -> next)
		node = node -> next;
	return (node);
}

void	*free_all(t_list **list, char *str)
{
	t_list	*temp;
	t_list	*l;

	l = *list;
	if (str)
		free(str);
	while (l)
	{
		temp = l;
		l = l -> next;
		free(temp->content);
		free(temp);
	}
	*list = NULL;
	return (NULL);
}

char	*rest_str(char *last)
{
	while (*last != '\0')
	{
		if (*last == '\n')
			break ;
		last++;
	}
	if (*last == '\n')
		last++;
	return (last);
}

size_t	str_lenth(char *str)
{
	size_t	len;

	len = 0;
	if (*str == '\0')
		return (0);
	while (str[len])
		len++;
	return (len);
}
