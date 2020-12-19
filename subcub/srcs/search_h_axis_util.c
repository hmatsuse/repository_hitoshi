/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_h_axis_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 01:17:03 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/17 02:09:09 by keiichiro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		set_h_wall(t_player *p, double x, double y)
{
	p->h_wall_x = x;
	p->h_wall_y = y;
}

void		find_wall_h_point(t_player *p)
{
	double	next_x;
	double	next_y;

	next_h_point(p, &next_x, &next_y);
	if (TRUE == founds_h_point(p, next_x, next_y))
		return ;
	set_h_wall(p, MAX_RANGE, MAX_RANGE);
}
