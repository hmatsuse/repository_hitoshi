/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val_v_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 13:37:52 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 23:42:56 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_val_h(t_player *p, double fixed_ray_angle)
{
	double tangent;

	if (p->ray_up)
		p->h_const_y = -BLOCK_LEN;
	else
		p->h_const_y = BLOCK_LEN;
	tangent = tan((PI / 2) - fixed_ray_angle);
	if (p->ray_right)
		p->h_const_x = BLOCK_LEN * tangent;
	else
		p->h_const_x = -BLOCK_LEN * tangent;
}

void	set_val_v(t_player *p, double fixed_ray_angle)
{
	double tangent;

	if (p->ray_right)
		p->v_const_x = BLOCK_LEN;
	else
		p->v_const_x = -BLOCK_LEN;
	tangent = tan((PI / 2) - fixed_ray_angle);
	if (p->ray_up)
		p->v_const_y = -BLOCK_LEN / tangent;
	else
		p->v_const_y = BLOCK_LEN / tangent;
}

void	set_value_v_h(t_player *p, double fixed_ray_angle, char c)
{
	if ('v' == c)
		set_val_v(p, fixed_ray_angle);
	else
		set_val_h(p, fixed_ray_angle);
}
