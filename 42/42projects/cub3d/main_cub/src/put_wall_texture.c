/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:31:59 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/17 21:58:09 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_p_view(t_player *p, double current_x, double current_y)
{
	double	angle;
	int		x;

	x = 0;
	angle = -(p->view_angle / 2);
	get_len_to_sprite(p, current_x, current_y);
}

void	put_world(t_player *p)
{
	get_turn_dir(p);
	put_p_view(p, p->current_x, p->current_y);
}