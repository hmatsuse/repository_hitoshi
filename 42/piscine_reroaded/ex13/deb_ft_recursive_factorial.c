/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_recursive_factorial.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 00:17:59 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 00:17:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_recursive_factorial(int nb)
{
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (1);
    else    
        return (nb * ft_recursive_factorial(nb - 1));
}

int     main(void)
{
    printf("%d\n", ft_recursive_factorial(5));
    printf("%d\n", ft_recursive_factorial(0));
    return (0);
}