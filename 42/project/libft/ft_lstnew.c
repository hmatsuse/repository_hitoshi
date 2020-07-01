/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 14:37:31 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/01 19:23:13 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;
	size_t	size;

	if (!content)
		return (malloc(0));
	size = ft_strlen(content) + 1;
	if (!(tmp = malloc(sizeof(void *) * size)))
		return (NULL);
	tmp->content = content;
	return (tmp);
}
