/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_print_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:06:19 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 16:06:19 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);

void    ft_print_numbers(void)
{
    int n;

    n = '0';
    while (n <= '9')
    {
        ft_putchar(n);
        n++;
    }
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main(void)
{
    ft_print_numbers();
    return (0);
}
