/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_world_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:01:16 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/15 18:37:03 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    input_dir(t_map *map_info, char *line, int *len, int i)
{
    char *tmp;

    if (TRUE == map_info->found_start_pos)
        err_exit(MAP_ERR);
    if (!(tmp = ft_strdup(&line[i])))
        err_exit(MAP_ERR);
    map_info->world_map[*len][i] = *tmp;
    map_info->found_start_pos = TRUE;
    map_info->p_init_pos_x = i;
    map_info->p_init_pos_y = *len;
    free(tmp);
}

void    add_zero(t_map *map_info, size_t len_line, int *len)
{
    if (len_line != 0 && (int)len_line < map_info->map_width)
    {
        while ((int)len_line < map_info->map_width)
        {
            map_info->world_map[*len][len_line] = '0';
            len_line++;
        }
        map_info->world_map[*len][len_line] = '\0';
    }
}

void    input_map(t_map *map_info, char *line, size_t len_line, int *len)
{
    int i;

    i = 0;
    while (i < (int)len_line)
    {
        if (FALSE == is_map(line))
            err_exit(MAP_ERR);
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '0')
            map_info->world_map[*len][i] = '0';
        else if (line[i] == '1')
            map_info->world_map[*len][i] = '1';
        else if (line[i] == '2')
            map_info->world_map[*len][i] = '2';
        else if (line[i] == 'N' || line[i] == 'E' || \
            line[i] == 'S' || line[i] == 'W')
            input_dir(map_info, line, len, i);
        else
            map_info->world_map[*len][i] = '0';
        i++;
    }
    map_info->world_map[*len][i] = '\0';
}

void	check_info(t_map *map_info)
{
	if (TRUE == map_info->found_r && TRUE == map_info->found_no &&
		TRUE == map_info->found_so && TRUE == map_info->found_we &&
		TRUE == map_info->found_ea && TRUE == map_info->found_s &&
		TRUE == map_info->found_f && TRUE == map_info->found_c)
		return ;
	else
		err_exit(MAP_ERR);
}

void    get_map(char *line, int *len, t_player *p, size_t len_line)
{
    check_info(&p->map);
    if (FALSE == is_map(line))
        err_exit(MAP_ERR);
    if (!(p->map.world_map[*len] = \
        (char *)malloc((sizeof(char) * (p->map.map_width + 1)))))
        err_exit(MALLOC_ERR);
    input_map(&p->map, line, len_line, len);
    add_zero(&p->map, len_line, len);
    input_sprite(p, line, len);
}
