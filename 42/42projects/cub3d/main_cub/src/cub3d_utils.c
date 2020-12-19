/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:37:02 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/14 17:42:58 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_strchar(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

char	*ft_strchar(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

void	skip_space(char *line, int *i)
{
	while (ft_strchar(" ", line[*i]))
		(*i)++;
}

void    ft_putstr_fd(char *s, int fd)
{
    if (s)
    {
        while (*s)
        {
            write(fd, &*s, 1);
            s++;
        }
    }
}
