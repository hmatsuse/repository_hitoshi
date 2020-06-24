/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 17:10:22 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/24 18:23:34 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	char *dest = dst;
	const char *ssrc = src;
	size_t n = dstsize;

	if (n != 0)
	{
		while (--n != 0)
		{
			if ((*dest++ = *ssrc++) == '\0')
				break;
		}
	}

	if (n == 0)
	{
		if (dstsize != 0)
			*dest = '\0';
		while (*ssrc++)
			;
	}
	return(ssrc - src - 1);
}
