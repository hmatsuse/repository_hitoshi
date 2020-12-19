/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_v_axis_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 01:22:15 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/17 01:59:54 by keiichiro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		set_v_wall(t_player *p, double x, double y)
{
	p->v_wall_x = x;
	p->v_wall_y = y;
}

void		first_wall_v_point(t_player *p)
{
	double	next_x;
	double	next_y;

	next_v_point(p, &next_x, &next_y);
	if (TRUE == founds_v_point(p, next_x, next_y))
		return ;
	set_v_wall(p, MAX_RANGE, MAX_RANGE);
}
