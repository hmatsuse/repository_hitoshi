/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:17:50 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/08 12:15:16 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*ssrc;

	dest = dst;
	ssrc = src;
	if (dst == src)
		return (dst);
	while (n-- > 0)
		*dest++ = *ssrc++;
	return (dst);
}
