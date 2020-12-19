/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:37:07 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/14 17:48:14 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	input_win_size(char *line, int *i, int *win_size)
{
	while (ft_strchar("1234567890", line[*i]))
	{
		*win_size = *win_size * 10 + (line[*i] - '0');
		(*i)++;
	}
}

void    get_win_size(t_map *map_info, char *line)
{
    int i;
    int win_x;
    int win_y;

    i = 0;
    win_x = 0;
    win_y = 0;
    if (ft_strchar("R", line[i]))
        i++;
    skip_space(line, &i);
    input_win_size(line, &i, &win_x);
	if (0 != line[i])
		err_exit(MAP_ERR);
	if (map_info->max_win_x < win_x)
		map_info->win_x = map_info->max_win_x;
	else
		map_info->win_x = win_x;
	if (map_info->max_win_y < win_y)
		map_info->win_y = map_info->max_win_y;
	else
		map_info->win_y = win_y;
    map_info->found_r++;
}
