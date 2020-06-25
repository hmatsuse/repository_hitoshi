/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:20:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 11:59:47 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	char *dest;
	const char *ssrc;
	char ch;

	dest = dst;
	ssrc = src;
	ch = c;
	while (n-- > 0)
	{
		*dest++ = *ssrc++;
		if (*ssrc == ch)
			return (dst);
	}
	return (NULL);
}
