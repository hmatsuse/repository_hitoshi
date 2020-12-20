/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_background_clr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:14:04 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 21:23:08 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_color_num(char *line, t_map *map_info, int *i)
{
	while (line[*i] && ft_strchar("0123456789,", line[*i]))
	{
		if (3 == map_info->comma)
			error_quit(MAP_ERR);
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

void	ck_color_error(int red, int green, int blue)
{
	if (red < 0 || red > 255)
		error_quit(COLOR_ERR);
	if (green < 0 || green > 255)
		error_quit(COLOR_ERR);
	if (blue < 0 || blue > 255)
		error_quit(COLOR_ERR);
}

void	input_floor_celling_color(int *color, char *line, t_map *map_info)
{
	int		i;

	i = 2;
	skip_space(line, &i);
	get_color_num(line, map_info, &i);
	if ('-' == line[i])
		error_quit(MAP_ERR);
	ck_color_error(map_info->red, map_info->green, map_info->blue);
	*color = (map_info->red * (int)pow(16, 4)) + \
	(map_info->green * (int)pow(16, 2)) + map_info->blue;
}

void	g_background_color(t_map *map_info, char dir, char *line)
{
	map_info->red = 0;
	map_info->green = 0;
	map_info->blue = 0;
	map_info->comma = 0;
	if (dir == 'F')
	{
		input_floor_celling_color(&map_info->flr_color, line, map_info);
		map_info->ok_f++;
	}
	else if (dir == 'C')
	{
		input_floor_celling_color(&map_info->clg_color, line, map_info);
		map_info->ok_c++;
	}
}
