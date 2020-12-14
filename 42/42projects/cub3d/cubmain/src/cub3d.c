/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:14:52 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/13 18:28:01 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
	char *dst;

	dst = g->img_addr + (y * g->img_line_len + x * (g->img_bit_per_pix / 8));
	*(unsigned int*)dst = color;
}

void	put_player(t_game *g)
{
	int	range;
	double tmp_px;
	double tmp_py;
	double angle;

	tmp_px = g->px;
	tmp_py = g->py;
	angle = g->pa;
	range = 1;
	while (range < 50)
	{
		range++;
		tmp_px = cos(angle) * range + g->px;
		tmp_py = sin(angle) * range + g->py;
		my_mlx_pixel_put(g, tmp_px, tmp_py, 0x0000FF);
	}
	my_mlx_pixel_put(g, g->px, g->py, 0x000000);
}

void	draw_back_ground(t_game *g)
{
	int x = 0;
	int y = 0;

	while (y < 700)
	{
		while (x < 700)
		{
			my_mlx_pixel_put(g, x, y, 0xFFFFFF);
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_turn(t_game *g, int direction)
{
	g->pa += PI / 16 * direction;
}

void	ft_move(t_game *g, int move_dir)
{
	g->px = g->px + cos(g->pa) * MOVE_RANGE * move_dir;
	g->py = g->py + sin(g->pa) * MOVE_RANGE * move_dir;
	printf("g->px = [%f]\n", g->py);
	printf("g->px = [%f]\n", g->py);
}

void	put_map(t_game *g)
{
	int	i = 0;
	int	j = 0;
	while (i < WIN_WID)
	{
		while (j < WIN_HEI)
		{
			if (map[j / GRID][i / GRID] == 1 || i%64 == 0 || j%64 == 0)
				my_mlx_pixel_put(g, i, j, 0x00FF00);
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_player_move(int key, t_game *g)
{
	printf("key = %d\n", key);
	if (key == KEY_W)
		ft_move(g, 1);
	if (key == KEY_S)
		ft_move(g, -1);
	if (key == KEY_LEFT)
		ft_turn(g, -1);
	if (key == KEY_RIGHT)
		ft_turn(g, 1);
	draw_back_ground(g);
	put_map(g);
	put_player(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	return (0);
}

int		ft_puttmp(int key, t_game *g)
{
	printf("key = %d\n", key);
	write (1, "put[x]w",6 );
	exit(0);
	return (0);
}

int		main(void)
{
	t_game *g;

	char *line;
	int fd;

	// get_next_line(fd, &line);
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, 700, 700, "cub3d");
	g->img_ptr = mlx_new_image(g->mlx_ptr, 700, 700);
	g->img_addr = mlx_get_data_addr(g->img_ptr, &g->img_bit_per_pix, &g->img_line_len, &g->img_endian);

	g->px = WIN_WID / 2;
	g->py = WIN_HEI / 2;
	g->pa = PI * 1.5;
	
	mlx_hook(g->win_ptr, 2, 0, ft_player_move, g);
	mlx_hook(g->win_ptr, 17, 0, ft_puttmp, g);
	// mlx_hook(g->win_ptr, 17, 0, ft_puttmp, g);
	//2  キーボードが押されたら //3  キーを押すのをやめたら　//17　左上のバツ
	mlx_loop(g->mlx_ptr);
	return (0);
}

// int		main(int argc, char **argv)
// {
// 	if (3 == argc && ft_strcmp(argv[2], "--save"))
// 		cub_save(argv);
// 	else if (2 == argc)
// 		cub(argv);
// 	else
// 		er_exit(ARG_ERR):
// 	return (0);
// }