/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:12:31 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 04:42:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	read_line(t_map *map_info, char *line, int *len, t_player *p)
{
	size_t	len_line;

	if (line[0] == 'R' && line[1] == ' ')
		get_win_size(map_info, line);
	else if (line[0] == 'N' && line[1] == 'O')
		get_txt(p, 'N', line);
	else if (line[0] == 'S' && line[1] == 'O')
		get_txt(p, 'S', line);
	else if (line[0] == 'W' && line[1] == 'E')
		get_txt(p, 'W', line);
	else if (line[0] == 'E' && line[1] == 'A')
		get_txt(p, 'E', line);
	else if (line[0] == 'S' && line[1] == ' ')
		get_txt(p, 'P', line);
	else if (line[0] == 'F' && line[1] == ' ')
		get_background_color(map_info, 'F', line);
	else if (line[0] == 'C' && line[1] == ' ')
		get_background_color(map_info, 'C', line);
	else if ((len_line = ft_strlen(line)) != 0)
	{
		get_map(line, len, p, len_line);
		(*len)++;
	}
}

void	input_txt(t_player *player, t_txt *texture, char *line)
{
	int		i;

	i = 2;
	skip_space(line, &i);
	texture->name = ft_strdup(line + i);
	init_txt(player, texture);
}

void	get_txt(t_player *player, char dir, char *line)
{
	if (dir == 'N')
	{
		input_txt(player, &player->info_no, line);
		player->map.ok_no++;
	}
	else if (dir == 'S')
	{
		input_txt(player, &player->info_so, line);
		player->map.ok_so++;
	}
	else if (dir == 'W')
	{
		input_txt(player, &player->info_we, line);
		player->map.ok_we++;
	}
	else if (dir == 'E')
	{
		input_txt(player, &player->info_ea, line);
		player->map.ok_ea++;
	}
	else if (dir == 'P')
	{
		input_txt(player, &player->info_sp, line);
		player->map.ok_s++;
	}
}
