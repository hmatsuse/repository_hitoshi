/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:00:04 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 16:48:08 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t dstlen;
	size_t srclen;
	size_t di;
	size_t si;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	di = dstlen;
	si = 0;
	while (src[si] != '\0' && di + 1 < dstsize)
		dst[di++] = src[si++];
	dst[di] = '\0';
	return (srclen + ft_min(dstlen, dstsize));
}
