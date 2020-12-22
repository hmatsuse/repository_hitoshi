/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 16:40:52 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 16:40:52 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_putchar(char c);

void    ft_is_negative(int n)
{
    if (n < 0)
        ft_putchar('N');
    else
        ft_putchar('P');
}
