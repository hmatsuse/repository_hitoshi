/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_div_mod.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:41:20 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 17:41:20 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_div_mod(int a, int b, int *div, int *mod)
{
    *div = a / b;
    *mod = a % b;
}

int     main(void)
{
    int a;
    int b;
    int div;
    int mod;

    a = 13;
    b = 4;
    div = 0;
    mod = 0;

    ft_div_mod(a, b, &div, &mod);
    printf("%d %d\n",div ,mod);
    return (0);
}