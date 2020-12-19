/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:25:17 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/20 02:38:47 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	spin_right(t_player *p)
{
	draw_background(p);
	if (p->angle + TURN_SPEED > 2 * PI)
		p->angle = (p->angle + TURN_SPEED) - (2 * PI);
	else
		p->angle += TURN_SPEED;
	draw_world(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
}

void	spin_left(t_player *p)
{
	draw_background(p);
	if (p->angle - TURN_SPEED < 0)
		p->angle = (p->angle - TURN_SPEED) + (2 * PI);
	else
		p->angle -= TURN_SPEED;
	draw_world(p);
	mlx_put_image_to_window(p->mlx_ptr, p->win_ptr, p->img, 0, 0);
}

int		can_move(t_player *p, double move_x, double move_y)
{
	int		len_to_wall;
	int		x;
	int		y;

	len_to_wall = 1;
	while (1)
	{
		x = move_x + (len_to_wall * cos(p->angle));
		y = move_y + (len_to_wall * sin(p->angle));
		if (p->map.world_map[y / BLOCK_LEN][x / BLOCK_WIDTH] == '1')
			break ;
		len_to_wall++;
	}
	if (len_to_wall >= 5)
		return (TRUE);
	else
		return (FALSE);
}

void	clear_and_move(t_player *p, double move_x, double move_y)
{
	int		x;
	int		y;

	x = (int)(move_x) / BLOCK_WIDTH;
	y = (int)(move_y) / BLOCK_LEN;
	if (p->map.world_map[y][x] == '1')
		;
	else if (can_move(p, move_x, move_y))
	{
		draw_background(p);
		p->cur_x = move_x;
		p->cur_y = move_y;
		draw_world(p);
		mlx_put_image_to_window(p->mlx_ptr, \
			p->win_ptr, p->img, 0, 0);
	}
}

int		press_key(int key, t_player *p)
{
	mlx_do_sync(p->mlx_ptr);
	if (key == K_ESC)
		exit(0);
	else if (key == K_A)
		clear_and_move(p, p->cur_x + (MOVE_RANGE * cos(p->angle - (PI / 2))), \
		p->cur_y + (MOVE_RANGE * sin(p->angle - (PI / 2))));
	else if (key == K_S)
		clear_and_move(p, p->cur_x - (MOVE_RANGE) * cos(p->angle), \
		p->cur_y - (MOVE_RANGE) * sin(p->angle));
	else if (key == K_D)
		clear_and_move(p, p->cur_x + (MOVE_RANGE * cos(p->angle + (PI / 2))), \
		p->cur_y + (MOVE_RANGE * sin(p->angle + (PI / 2))));
	else if (key == K_W)
		clear_and_move(p, p->cur_x + (MOVE_RANGE * cos(p->angle)), \
		p->cur_y + (MOVE_RANGE * sin(p->angle)));
	else if (key == K_LEFT)
		spin_left(p);
	else if (key == K_RIGHT)
		spin_right(p);
	return (0);
}
