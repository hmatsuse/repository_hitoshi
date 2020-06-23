/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:21:29 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/22 17:21:29 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memset(void *b, int c, size_t len)
{
    const unsigned char uc = c;
    unsigned char       *p = (unsigned char *)b;

    while (len-- > 0)
        *p++ = uc;
    
    return (b);
}

int     main(void)
{
    char str[] = "0123456789";
    ft_memset(str+2, '/', 5);
    printf("%s\n", str);
    return (0);
}
