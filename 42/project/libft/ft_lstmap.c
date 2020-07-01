/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:46:37 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/01 22:14:56 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"	

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*list;
	t_list	*s;
	size_t	size;

	if (!lst)
		return (malloc(0));
	list = lst;
	while (lst)
	{
		size = ft_strlen(lst->content) + 1;
		if (!(tmp = malloc(sizeof(void *) * size)))
			return (NULL);
		tmp = f(lst->content);
		lst = lst->next;
	}
	while (list)
	{
		s = list;
		del(list->content);
		free(list);
		list = s->content;
	}
	list = NULL;
	return (tmp);
}
