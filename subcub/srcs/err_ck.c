/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_ck.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 19:42:30 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 14:52:29 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_quit(int num)
{
	if (TEX_ERR == num)
		perror("TEXTURE ERROR");
	else if (ARG_ERR == num)
		perror("MALLOC ERROR");
	else if (OPEN_ERR == num)
		perror("OPEN ERROR");
	else if (WIN_ERR == num)
		ft_putstr_fd("ARGUMENTS ERROR\n", 2);
	else if (MAP_ERR == num)
		ft_putstr_fd("MAP ERROR\n", 2);
	else if (COLOR_ERR == num)
		ft_putstr_fd("COLOR ERROR\n", 2);
	else if (MLC_ERR == num)
		ft_putstr_fd("WINDOW ERROR\n", 2);
	exit(1);
}

void	ck_irregular(t_player *player, int *x, int *y, int *flag)
{
	if (*x > player->map.map_width)
		(*flag)++;
	if (*x < 0)
		(*flag)++;
	if (*y > player->map.map_len)
		(*flag)++;
	if (*y < 0)
		(*flag)++;
}

int		press_close_botton(int key, t_player *p)
{
	p->ready_to_go = key;
	exit(0);
	return (0);
}

double	modify_angle(double angle)
{
	while (angle < 0)
		angle = (PI * 2) + angle;
	if (angle > PI * 2)
		angle = fmod(angle, (PI * 2));
	return (angle);
}

double	fix_angle(double angle)
{
	if (angle >= 3 * PI / 2 && angle <= 2 * PI)
		return ((2 * PI) - angle);
	else if (angle >= PI && angle < 3 * PI / 2)
		return (angle - PI);
	else if (angle > PI / 2 && angle < PI)
		return (PI - angle);
	else
		return (angle);
}
