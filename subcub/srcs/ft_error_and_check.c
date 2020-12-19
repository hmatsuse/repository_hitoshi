/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 22:29:30 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/20 02:35:45 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_quit(int num)
{
	if (TEX_ERR == num)
		perror("ERROR\ntexture error");
	else if (MLC_ERR == num)
		perror("ERROR\nmalloc error");
	else if (OPEN_ERR == num)
		perror("ERROR\nopen error");
	else if (COLOR_ERR == num)
		ft_putstr_fd("ERROR\ncolor error\n", 2);
	else if (MAP_ERR == num)
		ft_putstr_fd("ERROR\nmap data error\n", 2);
	else if (ARG_ERR == num)
		ft_putstr_fd("ERROR\narguments error\n", 2);
	else if (WIN_ERR == num)
		ft_putstr_fd("ERROR\nwindow size error\n", 2);
	exit(1);
}

void	check_irregular(t_player *player, int *x, int *y, int *flag)
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

int		ft_close_botton(int key, t_player *p)
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
