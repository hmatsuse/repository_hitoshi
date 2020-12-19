/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:40:57 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 04:41:17 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_player *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + ((y * p->line_length) + (x * (p->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}

void	cub3d(t_player p)
{
	p.win_ptr = mlx_new_window(p.mlx_ptr, p.map.win_x, p.map.win_y, "cub3D");
	p.img = mlx_new_image(p.mlx_ptr, p.map.win_x, p.map.win_y);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel
		, &p.line_length, &p.endian);
	get_p_pos(&p);
	check_map(&p);
	d_background(&p);
	d_wld(&p);
	mlx_put_image_to_window(p.mlx_ptr, p.win_ptr, p.img, 0, 0);
	mlx_hook(p.win_ptr, 2, 0, press_key, &p);
	mlx_hook(p.win_ptr, 17, 0, press_close_botton, &p);
	mlx_loop(p.mlx_ptr);
}

int		main(int argc, char *argv[])
{
	t_player	p;

	if (argc == 2 || (argc == 3 && ft_strcmp(argv[2], SAVE)))
	{
		p.map.name = argv[1];
		init_player(&p);
		init_map(&p.map);
		get_map_data(&p.map, &p);
		if (!(p.map.len_list = malloc(sizeof(int) * (p.map.win_x + 1))))
			error_quit(MLC_ERR);
		if (argc == 3 && ft_strcmp(argv[2], SAVE))
			make_bmp(p);
		else if (argc == 2)
			cub3d(p);
	}
	else
		error_quit(ARG_ERR);
	return (0);
}
