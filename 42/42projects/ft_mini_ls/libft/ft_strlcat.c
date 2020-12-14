/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 19:00:04 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/08 13:00:07 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_min(int s1, int s2)
{
	if (s1 < s2)
		return (s1);
	return (s2);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
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
