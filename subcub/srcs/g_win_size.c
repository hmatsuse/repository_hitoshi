/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_win_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 01:42:48 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 15:30:50 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	input_win_size(char *line, int *i, int *win_size)
{
	while (ft_strchar("1234567890", line[*i]))
	{
		*win_size = *win_size * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (*win_size <= 0)
		error_quit(MAP_ERR);
}

void	g_win_size(t_map *map_info, char *line)
{
	int		i;
	int		win_x;
	int		win_y;

	i = 0;
	win_x = 0;
	win_y = 0;
	if (ft_strchar("R", line[i]))
		i++;
	skip_space(line, &i);
	input_win_size(line, &i, &win_x);
	skip_space(line, &i);
	input_win_size(line, &i, &win_y);
	if (0 != line[i])
		error_quit(MAP_ERR);
	if (map_info->max_win_x < win_x)
		map_info->win_x = map_info->max_win_x;
	else
		map_info->win_x = win_x;
	if (map_info->max_win_y < win_y)
		map_info->win_y = map_info->max_win_y;
	else
		map_info->win_y = win_y;
	map_info->ok_r++;
}
