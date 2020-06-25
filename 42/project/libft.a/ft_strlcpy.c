/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:10:22 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 16:54:54 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t srclen;
	size_t di;
	size_t si;

	srclen = ft_strlen(src);
	di = 0;
	si = 0;
	if (dstsize != 0)
	{
		while (src[si] != '\0' && di + 1 < dstsize)
			dst[di++] = src[si++];
		dst[di] = '\0';
	}
	return (srclen);
}

// size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
// {
// 	char		*dest;
// 	const char	*ssrc;
// 	size_t		n;

// 	dest = dst;
// 	ssrc = src;
// 	n = dstsize;
// 	if (n != 0)
// 	{
// 		while (--n != 0)
// 		{
// 			if ((*dest++ = *ssrc++) == '\0')
// 				break ;
// 		}
// 	}
// 	if (n == 0)
// 	{
// 		if (dstsize != 0)
// 			*dest = '\0';
// 	}
// 	return (ft_strlen(src));
// }
