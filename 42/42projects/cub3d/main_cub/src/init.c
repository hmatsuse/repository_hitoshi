/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:01:55 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/16 16:56:47 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	img_init(t_player *p)
{
	p->img = mlx_new_image(p->mlx_ptr, p->map.win_x, p->map.win_y);
	p->addr = mlx_get_data_addr(p->img, &p->bits_per_pixel, \
	&p->line_length, &p->endian);
}

void	map_init(t_map *map_info)
{
	map_info->world_map = NULL;
	map_info->found_r = FALSE;
	map_info->found_no = FALSE;
	map_info->found_so = FALSE;
	map_info->found_we = FALSE;
	map_info->found_ea = FALSE;
	map_info->found_s = FALSE;
	map_info->found_f = FALSE;
	map_info->found_c = FALSE;
}

void	player_info_init(t_player *p)
{
	p->angle = PI / 2;
	p->current_x = 50;
	p->current_y = 50;
	p->mlx_ptr = mlx_init();
	p->spin_x = 0;
	p->spin_y = 0;
	p->is_ready = FALSE;
	p->scaling = DISTANCE_TO_PROJECTION_PLANE;
	p->view_angle = VIEW_ANGLE;
	p->is_hit_horizontal = FALSE;
	p->is_hit_vertical = FALSE;
	p->map.map_width = 0;
	mlx_get_screen_size(p->mlx_ptr, \
		&p->map.max_win_x, &p->map.max_win_y);
	p->map.found_start_pos = FALSE;
}
