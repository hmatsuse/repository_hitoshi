/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_floor_celling_color.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:52:00 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/15 16:52:11 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_color_err(int red, int green, int blue)
{
	if (red < 0 || red > 255)
		err_exit(COLOR_ERR);
	if (green < 0 || green > 255)
		err_exit(COLOR_ERR);
	if (blue < 0 || blue > 255)
		err_exit(COLOR_ERR);
}

void	get_color_num(char *line, t_map *map_info, int *i)
{
	while (line[*i] && ft_strchar("0123456789,", line[*i]))
	{
		if (3 == map_info->comma)
			put_error_and_exit(MAP_ERR);
		if (line[*i] != ',' && map_info->comma == 0)
			map_info->red = map_info->red * 10 + (line[*i] - '0');
		else if (line[*i] != ',' && map_info->comma == 1)
			map_info->green = map_info->green * 10 + (line[*i] - '0');
		else if (line[*i] != ',' && map_info->comma == 2)
			map_info->blue = map_info->blue * 10 + (line[*i] - '0');
		else if (line[*i] == ',')
			map_info->comma++;
		(*i)++;
	}
}

void    input_floor_celling_color(int *color, char *line, t_map *map_info)
{
    int i;

    i = 0;
    map_info->red = 0;
    map_info->green = 0;
    map_info->blue = 0;
    map_info->comma = 0;
    skip_space(line, &i);
    get_color_num(line, map_info, &i);
    if ('-' == line[i])
		err_exit(MAP_ERR);
	check_color_err(map_info->red, map_info->green, map_info->blue);
	*color = (map_info->red * (int)pow(16, 4)) + \
	(map_info->green * (int)pow(16, 2)) + map_info->blue;
}

void    get_floor_celling_color(t_map *map_info, char dir, char *line)
{
    if (dir == 'F')
    {
        input_floor_celling_color(&map_info->floor_color, line, map_info);
        map_info->found_f++;
    }
	else if (dir == 'C')
	{
		input_floor_celling_color(&map_info->ceilling_color, line, map_info);
		map_info->found_c++;
	}
}
