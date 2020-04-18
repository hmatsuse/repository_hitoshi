/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 17:12:56 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/07 17:12:56 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

int     main(void)
{
    int a;
    int b;

    a = 1;
    b = 2;

    printf("a = %d | b = %d\n",a ,b);
    ft_swap(&a, &b);
    printf("a = %d | b = %d\n",a ,b);
    return (0);
}