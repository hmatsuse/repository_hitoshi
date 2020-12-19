/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ceiling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:32:29 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/17 17:36:58 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_ceilling(t_player *p)
{
	int len;
	int width;

	len = 0;
	while (len < p->map.win_y / 2)
	{
		width = 0;
		while (width < p->map.win_x)
		{
			my_mlx_pixel_put(p, width, len, p->map.ceilling_color);
			width++;
		}
		len++;
	}
}