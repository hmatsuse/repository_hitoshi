/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 21:46:37 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/02 20:23:28 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(newlst = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&newlst, del);
		return (NULL);
	}
	tmp = newlst;
	while (lst->next)
	{
		if (!(tmp->next = ft_lstnew(f(lst->next->content))))
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (newlst);
}
