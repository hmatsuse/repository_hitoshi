/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:23:50 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/20 02:33:56 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	input_map(t_map *map_info, char *line, size_t len_line, int *len)
{
	int		x;

	x = 0;
	while (x < (int)len_line)
	{
		if (!is_map(line))
			error_quit(MAP_ERR);
		if (line[x] == ' ' || line[x] == '\t' || line[x] == '0')
			map_info->world_map[*len][x] = '0';
		else if (line[x] == '1')
			map_info->world_map[*len][x] = '1';
		else if (line[x] == '2')
			map_info->world_map[*len][x] = '2';
		else if (line[x] == 'N' || line[x] == 'E' || \
				line[x] == 'S' || line[x] == 'W')
			input_dir(map_info, line, len, x);
		else
			map_info->world_map[*len][x] = '0';
		x++;
	}
	map_info->world_map[*len][x] = '\0';
}

void	add_zero(t_map *map_info, size_t len_line, int *len)
{
	if (len_line != 0 && (int)len_line < map_info->map_width)
	{
		while ((int)len_line < map_info->map_width)
			map_info->world_map[*len][len_line++] = '0';
		map_info->world_map[*len][len_line] = '\0';
	}
}

void	input_sprite(t_player *player, char *line, int *len)
{
	int		x;

	x = 0;
	while (line[x])
	{
		if (ft_strchar("2", line[x]))
		{
			player->sp_array[player->map.sp_index].map_x = x;
			player->sp_array[player->map.sp_index].map_y = *len;
			player->map.sp_index++;
		}
		x++;
	}
}
