/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_iterative_factorial.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 19:30:59 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 19:30:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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

int     main(void)
{
    printf("%d\n", ft_iterative_factorial(7));
    printf("%d\n", ft_iterative_factorial(0));
    return (0);
}
