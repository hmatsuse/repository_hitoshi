/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_map_len_width_sp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:40:25 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 15:28:45 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cnt_len_width(t_map *map_info, char *line)
{
	size_t	line_len;

	line_len = ft_strlen(line);
	if (is_map_data(line, line_len))
	{
		map_info->map_len += 1;
		if (map_info->map_width < (int)line_len)
			map_info->map_width = line_len;
	}
}

void	cnt_sp(t_map *map_info, char *line)
{
	size_t	line_len;
	int		i;

	line_len = ft_strlen(line);
	if (is_map_data(line, line_len))
	{
		i = 0;
		while (line[i])
			if (ft_strchar("2", line[i++]))
				map_info->sp_num++;
	}
}

void	g_map_len_width_sp(t_map *map_info)
{
	int		fd;
	char	*line;

	if ((fd = open(map_info->name, O_RDONLY)) < 0)
		error_quit(OPEN_ERR);
	map_info->map_len = 0;
	map_info->sp_num = 0;
	while (get_next_line(fd, &line) > 0)
	{
		cnt_len_width(map_info, line);
		cnt_sp(map_info, line);
		free(line);
	}
	cnt_len_width(map_info, line);
	cnt_sp(map_info, line);
	free(line);
	close(fd);
}
