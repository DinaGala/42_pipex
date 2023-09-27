/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzhuzhle <nzhuzhle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:05:47 by nzhuzhle          #+#    #+#             */
/*   Updated: 2023/06/15 18:15:31 by nzhuzhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*str;
	long			lenth;

	str = NULL;
	lenth = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_to_buf(fd, &list, &lenth);
	if (list == NULL)
		return (NULL);
	str = malloc(lenth + 1);
	if (str == 0)
		return (free_all(&list, NULL));
	add_to_string(list, str, lenth);
	if (clean_list(&list) < 0)
		return (free_all(&list, str));
	if (*str == '\0')
		return (free_all(&list, str));
	return (str);
}

void	read_to_buf(int fd, t_list **list, long *lenth)
{
	long	bytes;
	char	*buf;

	bytes = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == 0)
		return ;
	while (bytes > 0 && check_line(last_node(*list), lenth) == 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == 0)
			break ;
		if (bytes > 0)
			bytes = save_to_list(list, buf, bytes);
		if (bytes < 0)
		{
			free_all(list, NULL);
			list = NULL;
			break ;
		}
	}
	free(buf);
}

long	save_to_list(t_list **list, char *buf, long bytes)
{
	long	i;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (-1);
	new_node -> next = NULL;
	new_node -> content = malloc(bytes + 1);
	if (!(new_node -> content))
	{
		free(new_node);
		return (-1);
	}
	i = -1;
	while (++i < bytes)
		new_node->content[i] = buf[i];
	new_node->content[bytes] = '\0';
	if (!(*list))
		*list = new_node;
	else
		last_node(*list)->next = new_node;
	return (1);
}

void	add_to_string(t_list *list, char *str, long lenth)
{
	long	i;
	long	j;

	i = 0;
	if (!list)
		return ;
	while (i < lenth)
	{
		j = 0;
		while (list->content[j] && i < lenth && list->content[j] != '\n')
			str[i++] = list->content[j++];
		if (list->content[j] == '\n')
			str[i++] = list->content[j];
		else if (!list->content[j])
			list = list -> next;
	}
	str[i] = '\0';
}

int	clean_list(t_list **list)
{
	t_list	*clean_node;
	char	*last;
	size_t	i;

	if (!(*list))
		return (1);
	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return (-1);
	clean_node->next = NULL;
	last = rest_str(last_node(*list)-> content);
	clean_node->content = malloc(str_lenth(last) + 1);
	if (!clean_node->content)
	{
		free(clean_node);
		return (-1);
	}
	i = -1;
	while (last[++i])
		clean_node->content[i] = last[i];
	clean_node->content[i] = '\0';
	free_all(list, NULL);
	*list = clean_node;
	return (1);
}
