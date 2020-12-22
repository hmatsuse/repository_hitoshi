/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_ft_print_alphabet.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:36:06 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 15:36:06 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c);

void    ft_print_alphabet(void)
{
    int c;

    c = 'a';
    while (c <= 'z')
    {
        ft_putchar(c);
        c++;
    }
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     main(void)
{
    ft_print_alphabet();
    return (0);
}
