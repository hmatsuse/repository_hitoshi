/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:34:33 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/17 02:07:58 by keiichiro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	draw_ceiling(t_player *p)
{
	int		len;
	int		width;

	len = 0;
	while (len < p->map.win_y / 2)
	{
		width = 0;
		while (width < p->map.win_x)
			my_mlx_pixel_put(p, width++, len, p->map.ceilling_color);
		len++;
	}
}

void	draw_floor(t_player *p)
{
	int		len;
	int		width;

	len = p->map.win_y / 2;
	while (len < p->map.win_y)
	{
		width = 0;
		while (width < p->map.win_x)
			my_mlx_pixel_put(p, width++, len, p->map.floor_color);
		len++;
	}
}

void	draw_background(t_player *p)
{
	draw_ceiling(p);
	draw_floor(p);
}
