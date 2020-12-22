/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:23:23 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/15 18:20:47 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	input_sprite(t_player *p, char *line, int *len)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_strchar("2", line[i]))
		{
			p->sp_list[p->map.sp_index].map_x = i;
			p->sp_list[p->map.sp_index].map_y = *len;
			p->map.sp_index++;
		}
		i++;
	}
}

void	sprite_init(t_map *map_info, t_player *player)
{
	t_sprite	new;

	if (!(player->sp_list = malloc(sizeof(t_sprite) * map_info->sp_num)))
		put_error_and_exit(MALLOC_ERR);
	map_info->sp_index = 0;
	while (map_info->sp_index < map_info->sp_num)
	{
		new.map_x = 0;
		new.map_y = 0;
		new.len_to_sprite = 1;
		new.start_x = 0;
		new.start_y = 0;
		new.found_start_pos = 0;
		player->sp_list[map_info->sp_index] = new;
		map_info->sp_index++;
	}
	map_info->sp_index = 0;
}
