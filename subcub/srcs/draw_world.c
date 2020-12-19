/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:25:51 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/20 03:29:40 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_turn_direction(t_player *player)
{
	player->dir_up = FALSE;
	player->dir_down = FALSE;
	player->dir_right = FALSE;
	player->dir_left = FALSE;
	if (PI <= player->angle && player->angle <= 2 * PI)
		player->dir_up = TRUE;
	if (PI > player->angle && player->angle >= 0)
		player->dir_down = TRUE;
	if ((PI * 3 / 2 <= player->angle && \
			player->angle <= 2 * PI) || (0 <= player->angle && \
			player->angle <= PI / 2))
		player->dir_right = TRUE;
	if (PI / 2 < player->angle && player->angle < PI * 3 / 2)
		player->dir_left = TRUE;
}

void	draw_p_view(t_player *p, double cur_x, double cur_y)
{
	double	angle;
	int		x;

	x = 0;
	angle = -1 * (p->view_angle / 2);
	get_len_to_sprite(p, cur_x, cur_y);
	sort_sprite(p, p->sp_array);
	while (x <= p->map.win_x)
	{
		p->ray_angle = p->angle + angle;
		fix_ray_angle(p);
		ray_direction(p);
		get_len_to_wall(p, cur_x, cur_y);
		p->map.len_list[x] = p->map.len_to_wall;
		put_wall_line(p, x, p->map);
		angle = angle + ((double)p->view_angle / p->map.win_x);
		x++;
	}
	p->map.len_list[x] = 0;
	draw_sprites(p, p->map.len_list, 0);
}

void	draw_world(t_player *p)
{
	get_turn_direction(p);
	draw_p_view(p, p->cur_x, p->cur_y);
}
