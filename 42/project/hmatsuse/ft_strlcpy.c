/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:10:22 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/07 20:13:16 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t di;
	size_t si;

	if (!dst)
		return ((size_t)NULL);
	di = 0;
	si = 0;
	if (dstsize != 0)
	{
		while (src[si] != '\0' && di + 1 < dstsize)
			dst[di++] = src[si++];
		dst[di] = '\0';
	}
	return (ft_strlen(src));
}
