/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 14:56:36 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/15 19:54:20 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	divide_line(t_map *map_info, char *line, int *len, t_player *p)
{
	size_t	len_line;

	if (line[0] == 'R' && line[1] == ' ')
		get_win_size(map_info, line);
	else if (line[0] == 'N' && line[1] == 'O')
		get_texture(p, 'N', line);
	else if (line[0] == 'S' && line[1] == 'O')
		get_texture(p, 'S', line);
	else if (line[0] == 'W' && line[1] == 'E')
		get_texture(p, 'W', line);
	else if (line[0] == 'E' && line[1] == 'A')
		get_texture(p, 'E', line);
	else if (line[0] == 'S' && line[1] == ' ')
		get_texture(p, 'P', line);
	else if (line[0] == 'F' && line[1] == ' ')
		get_floor_celling_color(map_info, 'F', line);
	else if (line[0] == 'C' && line[1] == ' ')
		get_floor_celling_color(map_info, 'C', line);
	else if ((len_line = ft_strlen(line)) != 0)
	{
		get_map(line, len, p, len_line);
		(*len)++;
	}
}

void    chk_f_name(char *name)
{
	int		i;

	i = 0;
	while (name[i])
		i++;
	i--;
	if (name[i] == 'b' && name[i - 1] == 'u' && \
		name[i - 2] == 'c' && name[i - 3] == '.')
		return ;
	else
		err_exit(MAP_ERR);
}

void	ft_strdup_2d(t_map *map_info)
{
	int		i;

	i = 0;
	while (i < map_info->map_len)
	{
		if (!(map_info->map_check[i] = ft_strdup(map_info->world_map[i])))
			err_exit(MALLOC_ERR);
		i++;
	}
	map_info->map_check[i] = NULL;
}

void    map_malloc(t_map *map_info)
{
    if (!(map_info->world_map = \
        (char**)malloc(sizeof(char *) * (map_info->map_len + 1))))
        err_exit(MALLOC_ERR);
    if (!(map_info->map_check = \
        (char**)malloc(sizeof(char *) * (map_info->map_len + 1))))
        err_exit(MALLOC_ERR);
}

int     get_map_data(t_map *map_info, t_player *p)
{
    int     fd;
    char    *line;
    int     len;

    chk_f_name(map_info->name);
    input_map_sprite(map_info);
    map_malloc(map_info);
    sprite_init(map_info, p);
    fd = open(map_info->name, O_RDONLY);
    if (fd == -1)
        err_exit(OPEN_ERR);
    len = 0;
    while (get_next_line(fd, &line) > 0)
    {
        divide_line(map_info, line, &len, p);
        free(line);
    }
    divide_line(map_info, line, &len, p);
    free(line);
    map_info->world_map[len] = NULL;
    check_info(&p->map);
    ft_strdup_2d(map_info);
    close(fd);
    return (0);
}