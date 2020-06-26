/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 18:48:50 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/26 20:11:10 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*box;
	size_t	boxsize;

	if (!count || !size)
		return (malloc(0));
	boxsize = count * size;
	box = malloc(boxsize);
	if (!box)
		return (NULL);
	ft_bzero(box, boxsize);
	return (box);
}
