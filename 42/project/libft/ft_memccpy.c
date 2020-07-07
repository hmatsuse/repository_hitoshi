/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:20:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/07 20:06:37 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*ssrc;

	i = 0;
	dest = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (n > 0)
	{
		dest[i] = ssrc[i];
		if (ssrc[i] == (unsigned char)c)
			return (&dst[i + 1]);
		n--;
		i++;
	}
	return (NULL);
}
