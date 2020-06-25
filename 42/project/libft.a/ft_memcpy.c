/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 11:53:02 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 11:53:02 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	register char *bbuf1;
	register const char *bbuf2;

	bbuf1 = dst;
	bbuf2 = src;
	while (n-- > 0)
		*bbuf1++ = *bbuf2++;
	return (dst);
}
