/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_is_negative.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:19:19 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 16:19:19 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);

void    ft_is_negative(int n)
{
    if (n < 0)
        ft_putchar('N');
    else
        ft_putchar('P');
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main(void)
{
    ft_is_negative('d');
    return (0);
}
