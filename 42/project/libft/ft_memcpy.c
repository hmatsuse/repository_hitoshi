/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 17:17:50 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/30 17:17:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
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
