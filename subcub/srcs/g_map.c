/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:51:38 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 15:30:30 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	input_dir(t_map *map_info, char *line, int *len, int x)
{
	char	*tmp;

	if (TRUE == map_info->found_st_pos)
		error_quit(MAP_ERR);
	if (!(tmp = ft_strdup(&line[x])))
		error_quit(MLC_ERR);
	map_info->world_map[*len][x] = *tmp;
	map_info->found_st_pos = TRUE;
	map_info->p_pos_st_x = x;
	map_info->p_pos_st_y = *len;
	free(tmp);
}

void	ck_info(t_map *map_info)
{
	if (map_info->ok_r && map_info->ok_no && map_info->ok_so
		&& map_info->ok_we && map_info->ok_ea && map_info->ok_s &&
		map_info->ok_f && map_info->ok_c)
		return ;
	else
		error_quit(MAP_ERR);
}

void	g_map(char *line, int *len, t_player *player, size_t len_line)
{
	ck_info(&player->map);
	if (!is_map(line))
		error_quit(MAP_ERR);
	if (!(player->map.world_map[*len] = \
		(char *)malloc((sizeof(char) * (player->map.map_width + 1)))))
		error_quit(MLC_ERR);
	input_map(&player->map, line, len_line, len);
	add_zero(&player->map, len_line, len);
	input_sp(player, line, len);
}
