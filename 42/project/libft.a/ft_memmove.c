/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:42:31 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/26 18:45:49 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    char        *dest;
	const char  *ssrc;
    const char  *t;

    dest = (char *)dst;
    ssrc = (const char *)src;
    if (len != 0)
    {
        if (dest < ssrc)
        {
            t = dest + len;
            while (ssrc != t)
                *dest++ = *ssrc++;
        }
        else if (dest > ssrc)
        {
            t = dest;
            dest += len;
            ssrc += len;
            while (dest != t)
                *--dest = *--ssrc;
        }
    }
	return (dest);
}

// int main(void)
// {
//     int size = 10;
//     char *dst = electric_alloc(size);
//     char *data = electric_alloc(size);

//     printf("%s\n", ft_memmove(dst, data, size));
//     return(0);
// }