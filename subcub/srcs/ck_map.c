/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:11:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 14:51:03 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		can_reach_to_x(t_player *p, int y, int x)
{
	int tmp_x;

	tmp_x = 0;
	if (NULL == p->map.ck_map[y])
		return (0);
	while (1)
	{
		if ('\0' == p->map.ck_map[y][tmp_x])
			return (0);
		if (tmp_x == x)
			return (1);
		tmp_x++;
	}
}

int		ck_with_dfs(t_player *p, int y, int x, int *valid)
{
	if (!(*valid) || 0 == y || 0 == x)
		return (*valid = 0);
	if (0 == can_reach_to_x(p, y + 1, x))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.ck_map[y][x + 1]))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.ck_map[y][x - 1]))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.ck_map[y + 1][x]))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.ck_map[y - 1][x]))
		return (*valid = 0);
	p->map.ck_map[y][x] = 'X';
	if (*valid && ft_strchar("02", p->map.ck_map[y + 1][x]))
		ck_with_dfs(p, y + 1, x, valid);
	if (*valid && ft_strchar("02", p->map.ck_map[y - 1][x]))
		ck_with_dfs(p, y - 1, x, valid);
	if (*valid && ft_strchar("02", p->map.ck_map[y][x + 1]))
		ck_with_dfs(p, y, x + 1, valid);
	if (*valid && ft_strchar("02", p->map.ck_map[y][x - 1]))
		ck_with_dfs(p, y, x - 1, valid);
	return (*valid);
}

void	ck_map(t_player *p)
{
	int	map_valid;

	map_valid = 1;
	ck_with_dfs(p, p->map.p_pos_st_y, p->map.p_pos_st_x, &map_valid);
	if (0 == map_valid)
		error_quit(MAP_ERR);
}
