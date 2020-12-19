/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_floor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:09:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/17 17:21:51 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_floor(t_player *p)
{
	int		len;
	int		width;

	len = p->map.win_y / 2;
	while (len < p->map.win_y)
	{
		width = 0;
		while (width < p->map.win_x)
		{
			my_mlx_pixel_put(p, width, len ,p->map.floor_color);
			width++;
		}
		len++;
	}
}