/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:59:14 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/17 16:58:39 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		can_reach_to_x(t_player *p, int y, int x)
{
	int tmp_x;

	tmp_x = 0;
	if (NULL == p->map.map_check[y])
		return (0);
	while (1)
	{
		if ('\0' == p->map.map_check[y][tmp_x])
			return (0);
		if (tmp_x == x)
			return (1);
		tmp_x++;
	}
}

int		try_dfs(t_player *p, int y, int x, int *valid)
{
	if (!(*valid) || 0 == y || 0 == x)
		return (*valid = 0);
	if (0 == can_reach_to_x(p, y + 1, x))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.map_check[y][x + 1]))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.map_check[y][x - 1]))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.map_check[y + 1][x]))
		return (*valid = 0);
	if (0 == ft_strchar("012X", p->map.map_check[y - 1][x]))
		return (*valid = 0);
	p->map.map_check[y][x] = 'X';
	if (*valid && ft_strchar("02", p->map.map_check[y + 1][x]))
		try_dfs(p, y + 1, x, valid);
	if (*valid && ft_strchar("02", p->map.map_check[y - 1][x]))
		try_dfs(p, y - 1, x, valid);
	if (*valid && ft_strchar("02", p->map.map_check[y][x + 1]))
		try_dfs(p, y, x + 1, valid);
	if (*valid && ft_strchar("02", p->map.map_check[y][x - 1]))
		try_dfs(p, y, x - 1, valid);
	return (*valid);
}

void    check_map(t_player *p)
{
    int x;
    int y;
    int map_valid;

    x = p->map.p_init_pos_x;
    y = p->map.p_init_pos_y;
    map_valid = 1;
    try_dfs(&p, x, y, map_valid);
}