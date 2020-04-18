/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deb_ft_strcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 15:47:19 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/08 15:47:19 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int     ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == s2[i])
            i++;
        else
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}

int     main(void)
{
    char s1[] = "\0";
    char s2[] = "000";

    printf("%d\n", ft_strcmp(s1, s2));
    return (0);
}