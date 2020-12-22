/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:24:48 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 15:24:48 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main(void)
{
    char str[] = "Hello World!";

    ft_putstr(str);
    return(0);
}
