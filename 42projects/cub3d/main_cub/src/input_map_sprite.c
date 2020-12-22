/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_map_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:11:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/14 15:55:17 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    cnt_map_len_width(t_map *map_info, char *line)
{
    size_t  len;

    len = ft_strlen(line);
    if (is_map_data(line, len))
    {
        map_info->map_len += 1;
        if (map_info->map_width < (int)len)
            map_info->map_width = len;
    }
}

void    cont_sprite(t_map *map_info, char *line)
{
    size_t  len;
    int		i;

	len = ft_strlen(line);
	if (is_map_data(line, len))
	{
		i = 0;
		while (line[i])
		{
			if (ft_strchar("2", line[i]))
				map_info->sp_num++;
			i++;
		}
	}
}

void    input_map_sprite(t_map *map_info)
{
    int     fd;
    char    *line;

    fd = open(map_info->name, O_RDONLY);
    if (fd == -1)
        err_exit(OPEN_ERR);
    map_info->map_len = 0;
    map_info->sp_num = 0;
    while (get_next_line(fd, &line) > 0)
    {
        cnt_map_len_width(map_info, line);
        cnt_sprite(map_info, line);
        free(line);
    }
	cnt_map_len_width(map_info, line);
	cnt_sprite(map_info, line);
	free(line);
	close(fd);
}