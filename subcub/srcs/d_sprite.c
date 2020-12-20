/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_sprite.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 11:39:27 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 14:50:41 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_sprite_color(t_player *data, int x, int y)
{
	int		color;

	color = *(unsigned int *)\
	(data->info_sp.addr + (y * 4 * TEXTURE_LEN) + (x * 4));
	return (color);
}

void	ck_sp_angle(t_player *p, double p_start_angle, int index)
{
	if (p_start_angle > PI * 3 / 2 && p->sp_array[index].angle < PI / 2)
		p->sp_array[index].angle += PI * 2;
	if (p_start_angle < PI / 2 && p->sp_array[index].angle > PI * 3 / 2)
		p->sp_array[index].angle -= PI * 2;
}

void	d_sp2(t_player *p, int index, int x)
{
	int		y;

	y = p->sp_array[index].st_y;
	while (y < p->sp_array[index].st_y + p->sp_array[index].hei_y)
	{
		if (y >= 0 && y < p->map.win_y)
		{
			p->sp_array[index].color = \
			get_sprite_color(p, ((x - p->sp_array[index].st_x) / \
				p->sp_array[index].hei_x) * TEXTURE_LEN, TEXTURE_LEN * \
				((y - p->sp_array[index].st_y) \
				/ p->sp_array[index].hei_y));
			if (p->sp_array[index].color >= 0)
				my_mlx_pixel_put(p, x, y, p->sp_array[index].color);
		}
		y++;
	}
}

void	d_sp1(t_player *p, int index, int *len_list, int x)
{
	while (x < p->sp_array[index].st_x + p->sp_array[index].hei_x)
	{
		if (x >= 0 && x < p->map.win_x && \
			len_list[x] > p->sp_array[index].len_to_sp)
			d_sp2(p, index, x);
		x++;
	}
}

void	d_sp(t_player *p, int *len_list, int index)
{
	int		x;
	double	sp_angle;
	double	p_start_angle;

	p->map.sp_index = 0;
	p_start_angle = modify_angle(p->angle - (VIEW_ANGLE / 2));
	while (index < p->map.sp_num)
	{
		ck_sp_angle(p, p_start_angle, index);
		init_sp_data(p, &sp_angle, p_start_angle, index);
		x = p->sp_array[index].st_x;
		d_sp1(p, index, len_list, x);
		index++;
	}
}
