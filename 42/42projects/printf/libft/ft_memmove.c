/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:57:48 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/29 12:39:05 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*dest;
	const char		*ssrc;

	if (dst <= src)
		ft_memcpy(dst, src, len);
	else
	{
		dest = dst + (len - 1);
		ssrc = src + (len - 1);
		while (len-- > 0)
			*dest-- = *ssrc--;
	}
	return (dst);
}
