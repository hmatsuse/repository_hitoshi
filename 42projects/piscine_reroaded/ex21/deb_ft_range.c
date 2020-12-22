/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_range.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:20:20 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/10 21:20:20 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int *ft_range(int min, int max)
{
    int *ptr;
    int i;

    if (min >= max)
        return (0);
    ptr = (int *)malloc(sizeof(int) * (max - min));
    if (!ptr)
        return (0);
    if (ptr)
    {
        i = 0;
        while (min < max)
        {
            ptr[i] = min;
            min++;
            i++;
        }
    }
    return (ptr);
}

int     main(void)
{
    int *num;
    int max;
    int min;
    int i;

    max = 110;
    min = 0;
    num = ft_range(min, max);
    i = 0;
    while (num[i] < max)
    {
        printf("%d\n", num[i]);
        i++;
    }
    return (0);
}
