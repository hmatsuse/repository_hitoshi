/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:21:36 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/22 17:21:36 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char *p = (unsigned char *)s;

    while(n-- > 0)
        *p++ = '0';
}

int     main()
{
    char str[] = "123456789";

    ft_bzero(str + 2, 3);
    printf("%s\n", str);
    return (0);
}
