/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_val_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:50:02 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 23:42:57 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	g_len_to_sp(t_player *p, double cur_x, double cur_y)
{
	double	len_x;
	double	len_y;

	p->map.sp_index = 0;
	len_x = 0;
	len_y = 0;
	while (p->map.sp_index < p->map.sp_num)
	{
		len_x = ((p->sp_array[p->map.sp_index].map_x * \
			BLOCK_LEN) + (BLOCK_LEN / 2)) - cur_x;
		len_y = ((p->sp_array[p->map.sp_index].map_y * \
			BLOCK_LEN) + (BLOCK_LEN / 2)) - cur_y;
		p->sp_array[p->map.sp_index].len_to_sp = hypot(len_x, len_y);
		p->sp_array[p->map.sp_index].angle = modify_angle(atan2(len_y, len_x));
		p->map.sp_index++;
	}
}

void	sort_sp(t_player *p, t_sp *sp_array)
{
	t_sp		tmp;
	int			num;

	num = 0;
	while (num < p->map.sp_num - 1)
	{
		p->map.sp_index = 0;
		while (p->map.sp_index < p->map.sp_num - 1)
		{
			if (sp_array[p->map.sp_index].len_to_sp < \
				sp_array[p->map.sp_index + 1].len_to_sp)
			{
				tmp = sp_array[p->map.sp_index];
				sp_array[p->map.sp_index] = sp_array[p->map.sp_index + 1];
				sp_array[p->map.sp_index + 1] = tmp;
			}
			p->map.sp_index++;
		}
		num++;
	}
}
