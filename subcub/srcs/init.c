/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 09:36:17 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 21:00:41 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_map(t_map *map_info)
{
	map_info->world_map = NULL;
	map_info->ok_r = FALSE;
	map_info->ok_no = FALSE;
	map_info->ok_so = FALSE;
	map_info->ok_we = FALSE;
	map_info->ok_ea = FALSE;
	map_info->ok_s = FALSE;
	map_info->ok_f = FALSE;
	map_info->ok_c = FALSE;
}

void	init_player(t_player *p)
{
	p->mlx_ptr = mlx_init();
	p->angle = PI / 2;
	p->cur_x = 50;
	p->cur_y = 50;
	p->spin_x = 0;
	p->spin_y = 0;
	p->is_touch_h = FALSE;
	p->is_touch_v = FALSE;
	p->map.map_width = 0;
	p->map.found_st_pos = FALSE;
	p->ready_to_go = FALSE;
	p->view_angle = VIEW_ANGLE;
	mlx_get_screen_size(p->mlx_ptr, &p->map.max_win_x, &p->map.max_win_y);
}

void	init_sp_data(t_player *p, double *sp_angle,
						double p_start_angle, int index)
{
	*sp_angle = p->sp_array[index].angle - p_start_angle;
	p->sp_array[index].f_len_to_sp = \
		cos(p->angle - p->sp_array[index].angle) \
		* p->sp_array[index].len_to_sp;
	p->sp_array[index].center_x = (*sp_angle / VIEW_ANGLE) * p->map.win_x;
	p->sp_array[index].hei_x = (((double)p->map.win_x) * BLOCK_LEN) \
		/ p->sp_array[index].len_to_sp;
	p->sp_array[index].hei_y = (((double)p->map.win_x) * BLOCK_LEN) \
		/ p->sp_array[index].f_len_to_sp;
	p->sp_array[index].st_x = \
		p->sp_array[index].center_x - ((((double)p->map.win_x) \
		* BLOCK_LEN) / p->sp_array[index].len_to_sp / 2);
	p->sp_array[index].st_y = \
		((double)(p->map.win_y / 2)) - (p->sp_array[index].hei_y / 2);
}

void	init_txt(t_player *player, t_txt *texture)
{
	texture->data = \
		mlx_xpm_file_to_image(player->mlx_ptr, \
		texture->name, &texture->width, &texture->height);
	if (texture->data == (void*)0)
		error_quit(TEX_ERR);
	if (texture->width != 64 || texture->height != 64)
		error_quit(TEX_ERR);
	texture->addr = mlx_get_data_addr(texture->data, &texture->per_pix, \
											&texture->length, &texture->endian);
}

void	init_sp(t_map *map_info, t_player *player)
{
	t_sp	tmp_sp;

	if (!(player->sp_array = malloc(sizeof(t_sp) * map_info->sp_num)))
		error_quit(MLC_ERR);
	map_info->sp_index = 0;
	while (map_info->sp_index < map_info->sp_num)
	{
		tmp_sp.map_x = 0;
		tmp_sp.map_y = 0;
		tmp_sp.len_to_sp = 1;
		tmp_sp.st_x = 0;
		tmp_sp.st_y = 0;
		tmp_sp.found_st_pos = 0;
		player->sp_array[map_info->sp_index] = tmp_sp;
		map_info->sp_index++;
	}
	map_info->sp_index = 0;
}
