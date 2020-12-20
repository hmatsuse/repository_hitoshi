/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_h_sup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:42:14 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 15:36:13 by hmatsuse         ###   ########.fr       */
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
	if (TRUE == find_h_point(p, next_x, next_y))
		return ;
	set_h_wall(p, MAX_RANGE, MAX_RANGE);
}
