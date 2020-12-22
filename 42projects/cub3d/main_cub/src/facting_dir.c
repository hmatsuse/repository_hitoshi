/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facting_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 18:41:05 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/17 18:53:44 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_turn_dir(t_player *p)
{
	p->is_facing_up = FALSE;
	p->is_facing_down = FALSE;
	p->is_facing_right = FALSE;
	p->is_facing_left = FALSE;
	if (PI <= p->angle && p->angle <= 2 * PI)
		p->is_facing_up = TRUE;
	if (PI > p->angle && p->angle >= 0)
		p->is_facing_down = TRUE;
	if ((PI * 3 / 2 <= p->angle && p->angle <= 2 * PI) || (0 <= p->angle && \
			p->angle <= PI / 2))
		p->is_facing_right = TRUE;
	if (PI / 2 < p->angle && p->angle < PI * 3 / 2)
		p->is_facing_left = TRUE;
}


