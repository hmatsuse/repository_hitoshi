/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:06:23 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 16:06:23 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
