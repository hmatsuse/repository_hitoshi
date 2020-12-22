/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 15:59:54 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/11 15:59:54 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
