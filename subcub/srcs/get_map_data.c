/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 10:43:06 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 04:43:19 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_strdup_map(t_map *map_info)
{
	int		i;

	i = 0;
	while (i < map_info->map_len)
	{
		if (!(map_info->check_map[i] = ft_strdup(map_info->world_map[i])))
			error_quit(MLC_ERR);
		i++;
	}
	map_info->check_map[i] = NULL;
}

void	map_malloc(t_map *map_info)
{
	if (!(map_info->world_map = \
		(char**)malloc(sizeof(char *) * (map_info->map_len + 1))))
		error_quit(MLC_ERR);
	if (!(map_info->check_map = \
		(char**)malloc(sizeof(char *) * (map_info->map_len + 1))))
		error_quit(MLC_ERR);
}

void	check_file_name(char *name)
{
	int		i;

	i = 0;
	while (name[i])
		i++;
	i--;
	if (ft_strcmp(&name[i - 3], CUB))
		return ;
	else
		error_quit(MAP_ERR);
}

void	open_map(t_map *map_info, t_player *p)
{
	int		fd;
	char	*line;
	int		len;

	if ((fd = open(map_info->name, O_RDONLY)) < 0)
		error_quit(OPEN_ERR);
	len = 0;
	while (get_next_line(fd, &line) > 0)
	{
		read_line(map_info, line, &len, p);
		free(line);
	}
	read_line(map_info, line, &len, p);
	map_info->world_map[len] = NULL;
	free(line);
	close(fd);
}

int		get_map_data(t_map *map_info, t_player *p)
{
	check_file_name(map_info->name);
	get_map_len_width_sp(map_info);
	map_malloc(map_info);
	init_sp(map_info, p);
	open_map(map_info, p);
	check_info(&p->map);
	ft_strdup_map(map_info);
	return (0);
}
