/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_v.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 09:31:32 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 20:08:24 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	first_v_point(t_player *p, double fixed_ray_angle)
{
	double	tangent;

	if (p->ray_right)
		p->v_cross_x = ((int)(p->cur_x / BLOCK_LEN)) * BLOCK_LEN + BLOCK_LEN;
	else
		p->v_cross_x = ((int)(p->cur_x / BLOCK_LEN)) * BLOCK_LEN - 0.01;
	tangent = tan((PI / 2) - fixed_ray_angle);
	if (p->ray_up)
		p->v_cross_y = p->cur_y - ((fabs(p->cur_x - p->v_cross_x)) / tangent);
	else
		p->v_cross_y = p->cur_y + ((fabs(p->cur_x - p->v_cross_x)) / tangent);
}

void		next_v_point(t_player *p, double *next_x, double *next_y)
{
	*next_x = p->v_cross_x + p->v_const_x;
	*next_y = p->v_cross_y + p->v_const_y;
	if (*next_x < 0)
		*next_x = 0;
	if (*next_y < 0)
		*next_y = 0;
	if (*next_x > INT_MAX)
		*next_x = INT_MAX;
	if (*next_y > INT_MAX)
		*next_y = INT_MAX;
	p->v_cross_x = *next_x;
	p->v_cross_y = *next_y;
}

int			find_v_point(t_player *p, double next_x, double next_y)
{
	int		x;
	int		y;

	while ((int)(next_x / BLOCK_LEN) < \
		p->map.map_width && (int)(next_y / BLOCK_LEN) < p->map.map_len)
	{
		x = (int)(next_x / BLOCK_LEN);
		y = (int)(next_y / BLOCK_LEN);
		if ('1' == p->map.world_map[y][x])
		{
			set_v_wall(p, next_x, next_y);
			return (TRUE);
		}
		else if (0 == next_x || 0 == next_y)
		{
			set_v_wall(p, next_x, next_y);
			return (TRUE);
		}
		else
			next_v_point(p, &next_x, &next_y);
	}
	return (FALSE);
}

void		find_v_cross(t_player *p, double fixed_ray_angle)
{
	int		x;
	int		y;

	first_v_point(p, fixed_ray_angle);
	x = (int)(p->v_cross_x / BLOCK_LEN);
	y = (int)(p->v_cross_y / BLOCK_LEN);
	if (x >= p->map.map_width)
		x = p->map.map_width - 1;
	if (x < 0)
		x = 0;
	if (y >= p->map.map_len)
		y = p->map.map_len - 1;
	if (y < 0)
		y = 0;
	if ('1' == p->map.world_map[y][x])
	{
		set_v_wall(p, p->v_cross_x, p->v_cross_y);
		return ;
	}
	set_const_value(p, fixed_ray_angle, 'v');
	first_wall_v_point(p);
}
