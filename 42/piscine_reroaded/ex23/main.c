/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:20:54 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/13 21:20:54 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_point.h"

void    set_point(t_point *point)
{
    point->x = 42;
    point->y = 21;
}

int     main(void)
{
    t_point point;

    set_point(&point);
    printf("%d\n", point.x);
    printf("%d\n", point.y);
    return (0);
}
