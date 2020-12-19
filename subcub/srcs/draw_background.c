/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:41:06 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 04:38:21 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "../includes/get_next_line.h"

void	d_clg(t_player *p)
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

void	d_flr(t_player *p)
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

void	d_background(t_player *p)
{
	d_clg(p);
	d_flr(p);
}
