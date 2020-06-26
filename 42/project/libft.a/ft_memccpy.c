/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:20:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/26 18:10:41 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,\
int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*ssrc;
	unsigned char		ch;

	i = 0;
	dest = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n > 0)
	{
		dest[i] = ssrc[i];
		if (ssrc[i] == ch)
			return (&dst[i + 1]);
		n--;
		i++;
	}
	return (NULL);
}
