/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:24:41 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/20 03:32:12 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	input_dir(t_map *map_info, char *line, int *len, int x)
{
	char	*tmp;

	if (TRUE == map_info->found_start_pos)
		error_quit(MAP_ERR);
	if (!(tmp = ft_strdup(&line[x])))
		error_quit(MLC_ERR);
	map_info->world_map[*len][x] = *tmp;
	map_info->found_start_pos = TRUE;
	map_info->p_start_pos_x = x;
	map_info->p_start_pos_y = *len;
	free(tmp);
}

void	check_info(t_map *map_info)
{
	if (map_info->ok_r && map_info->ok_no && map_info->ok_so
		&& map_info->ok_we && map_info->ok_ea && map_info->ok_s &&
		map_info->ok_f && map_info->ok_c)
		return ;
	else
		error_quit(MAP_ERR);
}

void	get_map(char *line, int *len, t_player *player, size_t len_line)
{
	check_info(&player->map);
	if (!is_map(line))
		error_quit(MAP_ERR);
	if (!(player->map.world_map[*len] = \
		(char *)malloc((sizeof(char) * (player->map.map_width + 1)))))
		error_quit(MLC_ERR);
	input_map(&player->map, line, len_line, len);
	add_zero(&player->map, len_line, len);
	input_sprite(player, line, len);
}
