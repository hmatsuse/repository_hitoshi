/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:42:31 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 12:11:02 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *dest;
	const char *ssrc;

    dest = dst;
    ssrc = src;
    if (len != 0)
    {
        if (dest < ssrc)
        {
            register const char *t;
            t = dest + len;
            while (ssrc != t)
                *dest++ = *ssrc++;
        }
        else if (dest > ssrc)
        {
            register const char *t;
            t = dest;
            dest += len;
            ssrc += len;
            while (dest != t)
                *--dest = *--ssrc;
        }
    }
	return (dest);
}
