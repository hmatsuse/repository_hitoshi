/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:22:53 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/20 03:23:34 by hmatsuse         ###   ########.fr       */
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

void	ray_direction(t_player *player)
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

void	get_len_to_wall(t_player *p, double cur_x, double cur_y)
{
	double	fixed_ray_angle;

	fixed_ray_angle = fix_angle(p->ray_angle);
	search_h_axis(p, fixed_ray_angle);
	search_v_axis(p, fixed_ray_angle);
	compare_v_and_h(p);
	p->map.start_wall_x = cur_x + (p->map.len_to_wall * cos(p->ray_angle));
	p->map.start_wall_y = cur_y + (p->map.len_to_wall * sin(p->ray_angle));
	p->map.fish_len_to_wall = cos(p->angle - p->ray_angle) * p->map.len_to_wall;
}

int		get_img_color(t_player *data, int x, int y)
{
	int		color;

	if (data->flg_hit_v && data->ray_right)
		color = *(unsigned int *)(data->info_ea.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	else if (data->flg_hit_v && data->ray_left)
		color = *(unsigned int *)(data->info_we.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	else if (data->flg_hit_h && data->ray_up)
		color = *(unsigned int *)(data->info_no.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	else
		color = *(unsigned int *)(data->info_so.addr
		+ (y * 4 * TEXTURE_LEN) + (x * 4));
	return (color);
}

void	put_wall_line(t_player *p, int map_block_x, t_map map)
{
	int		x;
	int		y;

	map.prj_slice_height = (((double)p->map.win_x) * 64)
		/ p->map.fish_len_to_wall;
	map.start_wall_position = ((double)(p->map.win_y / 2))
		- (map.prj_slice_height / 2);
	map.height = map.start_wall_position;
	if (p->flg_hit_v && (p->ray_right || p->ray_left))
		x = p->map.start_wall_y % TEXTURE_LEN;
	else
		x = p->map.start_wall_x % TEXTURE_LEN;
	while (map.height <= map.start_wall_position
			+ map.prj_slice_height)
	{
		y = TEXTURE_LEN * ((map.height - map.start_wall_position)
			/ map.prj_slice_height);
		if (map.height >= 0 && map.height < p->map.win_y)
		{
			map.color = get_img_color(p, x, y);
			my_mlx_pixel_put(p, map_block_x, (int)map.height, map.color);
		}
		map.height++;
	}
}
