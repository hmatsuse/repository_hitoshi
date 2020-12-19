/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:50:42 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/14 18:03:38 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	texture_init(t_player *p, t_texture *texture)
{
	texture->data = \
		mlx_xpm_file_to_image(p->mlx_ptr, \
		texture->file_name, &texture->width, &texture->height);
	if (texture->data == (void*)0)
		err_exit(TEXTURE_ERR);
	texture->addr = mlx_get_data_addr(texture->data, &texture->per_pixel, \
											&texture->length, &texture->endian);
}

void	input_texture(t_player *p, t_texture *texture, char *line)
{
	int		i;

	i = 2;
	skip_space(line, &i);
	texture->file_name = ft_strdup(line + i);
	texture_init(p, texture);
}

void	get_texture(t_player *p, char dir, char *line)
{
	if (dir == 'N')
	{
		input_texture(p, &p->tex_no, line);
		p->map.found_no++;
	}
	else if (dir == 'S')
	{
		input_texture(p, &p->tex_so, line);
		p->map.found_so++;
	}
	else if (dir == 'W')
	{
		input_texture(p, &p->tex_we, line);
		p->map.found_we++;
	}
	else if (dir == 'E')
	{
		input_texture(p, &p->tex_ea, line);
		p->map.found_ea++;
	}
	else if (dir == 'P')
	{
		input_texture(p, &p->tex_sprite, line);
		p->map.found_s++;
	}
}
