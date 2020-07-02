/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:46:37 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/02 13:47:52 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*list;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	list = newlst;

	while (lst->next)
	{
		if (!(list->next = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		lst = lst->next;
		list = list->next;
	}
	return (newlst);
}

// t_list	*newlist;
// 	t_list	*list;
// 	size_t	size;
// 	size_t	i;

// 	size = 0;
// 	i = 0;
// 	tmp = NULL;
// 	while (lst)
// 	{
// 		size = ft_strlen(lst->content);
// 		if (!(tmp = malloc(sizeof(void *) * size + 1)))
// 		{
// 			while (1)
// 			{
// 				del(lst->content);
// 				free(tmp);
// 			}
// 			return (NULL);
// 		}
// 		tmp = f(lst->content);
// 		if (i++ == 0)
// 			list = tmp;
// 		lst = lst->content;
// 	}
// 	return (list);