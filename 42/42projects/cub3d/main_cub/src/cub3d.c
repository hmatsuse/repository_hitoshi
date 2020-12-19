/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 13:24:38 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/17 18:31:46 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_player *p, int x, int y, int color)
{
	char	*dst;

	dst = p->addr + ((y * p->line_length) + (x * (p->bits_per_pixel / 8)));
	*(unsigned int*)dst = color;
}

void	err_exit(int num)
{
	if (TEXTURE_ERR == num)
		perror("TEXTURE ERROR");
	else if (MALLOC_ERR == num)
		perror("MALLOC ERROR");
	else if (OPEN_ERR == num)
		perror("OPEN ERROR");
	else if (COLOR_ERR == num)
		ft_putstr_fd("COLOR ERROR", 2);
	else if (MAP_ERR == num)
		ft_putstr_fd("MAP ERROR", 2);
	else if (ARG_ERR == num)
		ft_putstr_fd("ARG ERROR", 2);
	exit(1);
}

void	cub3d(char **argv)
{
	t_player p;

	p.map.name = argv[1];
	p_init(&p);
	map_init(&p.map);
	get_map_date(&p.map, &p);
	if (!(p.map.len_list = malloc(sizeof(int) * (p.map.win_x + 1))))
	p.win_ptr = mlx_new_window(p.win_ptr, p.map.win_x, p.map.win_y, "cub3D");
	img_init(&p);
	get_p_pos(&p);
	check_map(&p);
	put_floor(&p);
	put_ceilling(&p);
}

int		main(int argc, char **argv)
{
	if (3 == argc && ft_strcmp(argv[2], "--save"))
		cub3d_save(argv);
	else if (2 == argc)
		cub3d(argv);
	else
		err_exit(ARG_ERR);
	return (0);
}
