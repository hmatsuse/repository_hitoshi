/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 15:39:55 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 15:39:55 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
