/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_p_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:24:00 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/17 00:46:26 by knagashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fix_cur_pos(t_player *p, int x, int y)
{
	p->cur_x = x * BLOCK_WIDTH + (BLOCK_WIDTH / 2);
	p->cur_y = y * BLOCK_LEN + (BLOCK_LEN / 2);
	p->ready_to_go = TRUE;
}

void	get_p_dir(t_player *p, char map_word, int x, int y)
{
	if (map_word == 'N')
	{
		p->angle = PI * 3 / 2;
		fix_cur_pos(p, x, y);
	}
	else if (map_word == 'E')
	{
		p->angle = 0;
		fix_cur_pos(p, x, y);
	}
	else if (map_word == 'S')
	{
		p->angle = PI / 2;
		fix_cur_pos(p, x, y);
	}
	else if (map_word == 'W')
	{
		p->angle = PI;
		fix_cur_pos(p, x, y);
	}
}

void	get_p_pos(t_player *p)
{
	int		len;
	int		width;

	len = 0;
	while (len < p->map.map_len)
	{
		width = 0;
		while (width < p->map.map_width)
		{
			get_p_dir(p, p->map.world_map[len][width], width, len);
			if (p->ready_to_go)
				break ;
			width++;
		}
		len++;
	}
}
