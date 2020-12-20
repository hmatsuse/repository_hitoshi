/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_world_sup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 17:15:26 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 15:51:30 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fix_ray_angle(t_player *player)
{
	if (player->ray_angle > 2 * PI)
		player->ray_angle -= (2 * PI);
	if (player->ray_angle < 0)
		player->ray_angle += (2 * PI);
}

void	ray_dir(t_player *player)
{
	player->ray_up = FALSE;
	player->ray_down = FALSE;
	player->ray_right = FALSE;
	player->ray_left = FALSE;
	if (PI <= player->ray_angle && player->ray_angle <= 2 * PI)
		player->ray_up = TRUE;
	if (PI > player->ray_angle && player->ray_angle >= 0)
		player->ray_down = TRUE;
	if ((PI * 3 / 2 <= player->ray_angle && player->ray_angle <= 2 * PI) || \
			(0 <= player->ray_angle && player->ray_angle <= PI / 2))
		player->ray_right = TRUE;
	if (PI / 2 < player->ray_angle && player->ray_angle < PI * 3 / 2)
		player->ray_left = TRUE;
}

int		g_img_color(t_player *data, int x, int y)
{
	int		color;

	if (data->is_touch_v && data->ray_right)
		color = *(unsigned int *)(data->info_ea.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	else if (data->is_touch_v && data->ray_left)
		color = *(unsigned int *)(data->info_we.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	else if (data->is_touch_h && data->ray_up)
		color = *(unsigned int *)(data->info_no.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	else
		color = *(unsigned int *)(data->info_so.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	return (color);
}

void	g_len_to_wall(t_player *p, double cur_x, double cur_y)
{
	double	fixed_ray_angle;

	fixed_ray_angle = fix_angle(p->ray_angle);
	find_h_cross(p, fixed_ray_angle);
	find_v_cross(p, fixed_ray_angle);
	compare_v_and_h(p);
	p->map.wall_st_x = cur_x + (p->map.len_to_wall * cos(p->ray_angle));
	p->map.wall_st_y = cur_y + (p->map.len_to_wall * sin(p->ray_angle));
	p->map.fish_len_to_wall = cos(p->angle - p->ray_angle) * p->map.len_to_wall;
}

void	put_wall_line(t_player *p, int map_block_x, t_map map)
{
	int		x;
	int		y;

	map.prj_slice_height = (((double)p->map.win_x) * 64)
		/ p->map.fish_len_to_wall;
	map.wall_st_pos = ((double)(p->map.win_y / 2))
		- (map.prj_slice_height / 2);
	map.height = map.wall_st_pos;
	if (p->is_touch_v && (p->ray_right || p->ray_left))
		x = p->map.wall_st_y % TEXTURE_LEN;
	else
		x = p->map.wall_st_x % TEXTURE_LEN;
	while (map.height <= map.wall_st_pos
			+ map.prj_slice_height)
	{
		y = TEXTURE_LEN * ((map.height - map.wall_st_pos)
			/ map.prj_slice_height);
		if (map.height >= 0 && map.height < p->map.win_y)
		{
			map.color = g_img_color(p, x, y);
			my_mlx_pixel_put(p, map_block_x, (int)map.height, map.color);
		}
		map.height++;
	}
}
