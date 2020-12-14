/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:24:10 by tkodai            #+#    #+#             */
/*   Updated: 2020/12/11 21:23:19 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// #include "minilibx_mms_20200219/mlx.h"
// #include <stdio.h>
// #include <unistd.h>
// #include <math.h>

// #define KEY_W		13
// #define KEY_S		1
// #define KEY_A		0
// #define KEY_D		2
// #define KEY_LEFT	123
// #define KEY_RIGHT	124
// #define PI			3.1415926534
// #define	MOVE_RANGE	5
// #define	GRID		64


// int	g_map[10][10] = 
// {
// 	{0, 0, 0, 0, 0, 0, 0, 0},
// 	{0, 1, 1, 1, 1, 1, 1, 1},
// 	{0, 1, 0, 0, 0, 0, 0, 1},
// 	{0, 1, 0, 0, 0, 0, 0, 1},
// 	{0, 1, 0, 0, 0, 0, 0, 1},
// 	{0, 1, 0, 0, 0, 0, 0, 1},
// 	{0, 1, 0, 0, 0, 0, 0, 1},
// 	{0, 1, 1, 1, 1, 1, 1, 1}
// };

// typedef struct 		s_game
// {
// 	void	*mlx_ptr;	
// 	void	*win_ptr;
// 	void	*img_ptr;
// 	void	*img_addr;

// 	int		img_bit_per_pix;
// 	int		img_endian;
// 	int		img_line_len;

// 	//player x
// 	double	px;
// 	//player y
// 	double	py;
// 	//player angle
// 	double	pa;

// }					t_game;

void	my_mlx_pixel_put(t_game *g, int x, int y, int color)
{
	char *dst;

	dst = g->img_addr + (y * g->img_line_len + x * (g->img_bit_per_pix / 8));
	*(unsigned int*)dst = color;
}

//  0  1  2
//0[R][R][G] 1[R][B][B] 2[R][B][B]
//1[R][B][B]
//2[R][B][B]
//
//
//[R][R][G]
//[R][B][B]
//
//
//0xFF0000
//img_addr = 00FF0000 00FF0000
// 

void	put_player(t_game *g)
{
	int 	range = 1;
	double	tmp_px = g->px;
	double	tmp_py = g->py;

	range = 1;
	tmp_px = g->px;
	tmp_py = g->py;
	double angle = g->pa - (PI / 6);
	// tmp_py = g->py/64*64;
	// tmp_px = g->px + (g->py - tmp_py)/tan(angle);
	while (angle <= g->pa + (PI / 6))
	{
		while (g_map[(int)tmp_py / GRID][(int)tmp_px / GRID] == 0)
		{
			range++;
			tmp_px = cos(angle) * range + g->px;
			tmp_py = sin(angle) * range + g->py;
			// tmp_px = cos(angle) * range + g->px;
			// tmp_py = sin(angle) * range + g->py;
			my_mlx_pixel_put(g, tmp_px, tmp_py, 0x0000FF);
		}
		range = 1;
		tmp_px = g->px;
		tmp_py = g->py;
		angle += (PI / 1000);
	}

	range = 1;
	tmp_px = g->px;
	tmp_py = g->py;
	while (range++)
	{
		if (g_map[(int)tmp_py / GRID][(int)tmp_px / GRID] == 1)
			break ;

		tmp_px = cos(g->pa) * range + g->px;
		tmp_py = sin(g->pa) * range + g->py;
		my_mlx_pixel_put(g, tmp_px, tmp_py, 0xFF0000);
	}
	range = 1;
	tmp_px = g->px;
	tmp_py = g->py;
	while (range++)
	{
		if (g_map[(int)tmp_py / GRID][(int)tmp_px / GRID] == 1)
			break ;

		tmp_px = cos(g->pa + (PI / 6)) * range + g->px;
		tmp_py = sin(g->pa + (PI / 6)) * range + g->py;
		my_mlx_pixel_put(g, tmp_px, tmp_py, 0xFF0000);
	}
	range = 1;
	tmp_px = g->px;
	tmp_py = g->py;
	while (range++)
	{
		if (g_map[(int)tmp_py / GRID][(int)tmp_px / GRID] == 1)
			break ;
		tmp_px = cos(g->pa - (PI / 6)) * range + g->px;
		tmp_py = sin(g->pa - (PI / 6)) * range + g->py;
		my_mlx_pixel_put(g, tmp_px, tmp_py, 0xFF0000);
	}
	my_mlx_pixel_put(g, g->px, g->py, 0xFF0000);
//RGB
}

void	draw_back_ground(t_game *g)
{
	int x = 0;
	int y = 0;

	while (y < 500)
	{
		while (x < 500)
		{
			my_mlx_pixel_put(g, x, y, 0x000000);
			x++;
		}
		x = 0;
		y++;
	}
}

//range = 壁との距離
//壁の大きさ　/ range;

void	put_map(t_game *g)
{
	int x = 0;
	int y = 0;


	while (y < 500)
	{
		while (x < 500)
		{
			if (g_map[y / GRID][x / GRID] == 1)
				my_mlx_pixel_put(g, x, y, 0x00FF00);
			x++;
		}
		x = 0;
		y++;
	}
}

void	cub3d_1(t_game *g)
{

	draw_back_ground(g);
	put_map(g);
	put_player(g);
//	dda_1(g);
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
}

void	ft_move(t_game *g, int move_dir)
{
	g->px = cos(g->pa) * MOVE_RANGE * move_dir + g->px;
	g->py = sin(g->pa) * MOVE_RANGE * move_dir + g->py;
}
//1111111111111111111
//1000000000000000001 p y6 x5
//1000000000000000001 
//1000000000000000001
//1000000000000000001
//1000000000000000001
//1000000000000000001
//1000000000000000001
//1111111111111111111
void	ft_turn(t_game *g, int direction)
{
	g->pa += PI / 8 * direction;
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
	cub3d_1(g);
	return (0);
}

int		ft_puttmp(int key, t_game *g)
{
	printf("key = %d\n", key);
	write (1, "put[x]",6 );
	return (0);
}

void	ft_hooks(t_game *g)
{
	mlx_hook(g->win_ptr, 2, 0, ft_player_move, g);
	mlx_hook(g->win_ptr, 17, 0, ft_puttmp, g);

	//2  キーボードが押されたら //3  キーを押すのをやめたら　//17　左上のバツ
	mlx_loop(g->mlx_ptr);
}
//mlx_hook無視される
//mlx_loop
//
//
//
//mlx_hook()

void	init_game(t_game *g)
{
	g->mlx_ptr = mlx_init();
	g->win_ptr = mlx_new_window(g->mlx_ptr, 700, 700, "cub3d");
	g->img_ptr = mlx_new_image(g->mlx_ptr, 700, 700);
	g->img_addr = mlx_get_data_addr(g->img_ptr, &g->img_bit_per_pix, &g->img_line_len, &g->img_endian);

	g->px = 250;
	g->py = 250;
	g->pa = 0;


	//new window
	//500500
	//iimage <- カキコミ
	//
	ft_hooks(g);
}

int		main()
{
	printf("1\n");

	t_game g;
	init_game(&g);
	return (0);
}

// Playerの現在地
// 
