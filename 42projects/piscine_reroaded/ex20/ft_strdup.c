/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/10 21:14:47 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/04/10 21:14:47 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     ft_strlen(char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
        i++;
    return(i);
}

char    *ft_strcpy(char *ptr, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        ptr[i] = src[i];
        i++;
    }
    ptr[i] = '\0';
    return (ptr);
}

char    *ft_strdup(char *src)
{
    char *ptr;

    ptr = malloc(sizeof(char) * (ft_strlen(src) + 1));
    if (!ptr)
        return (0);
    if (ptr)
        ft_strcpy(ptr, src);
    return (ptr);
}
