/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_sqrt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 14:43:56 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 14:43:56 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_sqrt(int nb)
{
    int i;

    i = 1;
    if (nb == 0)
        return (0);
    while (i <= nb)
    {
        if (i > 46340)
            return (0);
        if (i * i == nb)
            return (i);
        i++;
    }
    return(0);
}

int     main(void)
{
    printf("%d\n", ft_sqrt(9));
    printf("%d\n", ft_sqrt(46340));
    printf("%d\n", ft_sqrt(12250000));
    printf("%d\n", ft_sqrt(2147483647));
    return (0);
}