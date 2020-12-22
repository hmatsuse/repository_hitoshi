/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 00:13:14 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 00:13:14 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_iterative_factorial(int nb)
{
    int ans;

    ans = 1;
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    while (nb != 0)
    {
        ans *= nb;
        nb--;
    }
    return (ans);
}
