/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 21:59:55 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/18 00:57:06 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    get_len_to_sprite(t_player *p, double current_x, double current_y)
{
    double len_x;
    double len_y;

    p->map.sp_index = 0;
    len_x = 0;
    len_y = 0;
    while (p->map.sp_index < p->map.sp_num)
    {
        len_x = ((p->sp_list[p->map.sp_index].map_x * \
            BLOCK_LEN) + (BLOCK_LEN / 2)) - current_x;
        len_y = ((p->sp_list[p->map.sp_index].map_y * \
            BLOCK_LEN) + (BLOCK_LEN / 2)) - current_y;
        p->sp_list[p->map.sp_index].len_to_sprite = \
			hypot(len_x, len_y);//図ったx、yを元に自分とspriteの距離を測る
		p->sp_list[p->map.sp_index].angle = \
			atan2(len_y, len_x);//spriteとの角度を出す
		p->sp_list[p->map.sp_index].angle = \
			make_validate_angle(p->sp_list[p->map.sp_index].angle);//角度を正しい角度にする（実際は30度なのに330度の場合など）
		p->map.sp_index++;
    }
}