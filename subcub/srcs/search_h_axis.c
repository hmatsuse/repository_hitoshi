/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_h_axis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:23:03 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/17 22:21:10 by knagashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	first_h_point(t_player *p, double fixed_ray_angle)
{
	double	tangent;

	if (p->ray_up)
		p->h_axis_y = ((int)(p->cur_y / BLOCK_LEN)) * BLOCK_LEN - 0.01;
	else
		p->h_axis_y = ((int)(p->cur_y / BLOCK_LEN)) * BLOCK_LEN + BLOCK_LEN;
	tangent = tan((PI / 2) - fixed_ray_angle);
	if (p->ray_right)
		p->h_axis_x = p->cur_x + ((fabs(p->cur_y - p->h_axis_y)) * tangent);
	else
		p->h_axis_x = p->cur_x - ((fabs(p->cur_y - p->h_axis_y)) * tangent);
}

void		next_h_point(t_player *p, double *next_x, double *next_y)
{
	*next_x = p->h_axis_x + p->h_const_x;
	*next_y = p->h_axis_y + p->h_const_y;
	if (*next_x < 0)
		*next_x = 0;
	if (*next_y < 0)
		*next_y = 0;
	if (*next_x > INT_MAX)
		*next_x = INT_MAX;
	if (*next_y > INT_MAX)
		*next_y = INT_MAX;
	p->h_axis_x = *next_x;
	p->h_axis_y = *next_y;
}

int			founds_h_point(t_player *p, double next_x, double next_y)
{
	int		x;
	int		y;

	while ((int)(next_x / BLOCK_LEN) < p->map.map_width && \
			(int)(next_y / BLOCK_LEN) < p->map.map_len)
	{
		x = (int)(next_x / BLOCK_LEN);
		y = (int)(next_y / BLOCK_LEN);
		if ('1' == p->map.world_map[y][x])
		{
			set_h_wall(p, next_x, next_y);
			return (TRUE);
		}
		else if (0 == next_x || 0 == next_y)
		{
			set_h_wall(p, next_x, next_y);
			return (TRUE);
		}
		else
			next_h_point(p, &next_x, &next_y);
	}
	return (FALSE);
}

void		search_h_axis(t_player *p, double fixed_ray_angle)
{
	int		x;
	int		y;
	int		flag;

	first_h_point(p, fixed_ray_angle);
	x = (int)(p->h_axis_x / BLOCK_LEN);
	y = (int)(p->h_axis_y / BLOCK_LEN);
	flag = 0;
	check_irregular(p, &x, &y, &flag);
	if (flag > 0)
	{
		set_h_wall(p, MAX_RANGE, MAX_RANGE);
		return ;
	}
	if ('1' == p->map.world_map[y][x])
	{
		set_h_wall(p, p->h_axis_x, p->h_axis_y);
		return ;
	}
	set_const_value(p, fixed_ray_angle, 'h');
	find_wall_h_point(p);
}
