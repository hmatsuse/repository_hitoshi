/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:11:52 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 23:34:45 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "get_next_line.h"
# include <math.h>
# include <float.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define PI 3.14159265359
# define TRUE 1
# define FALSE 0
# define SAVE "--save"
# define CUB ".cub"
# define NUM "1234567890"
# define BLOCK_LEN 64
# define BLOCK_WIDTH 64
# define MAX_RANGE 1000000
# define K_ESC 53
# define K_A 0
# define K_S 1
# define K_D 2
# define K_W 13
# define K_LEFT 123
# define K_RIGHT 124
# define TEX_ERR 1
# define MLC_ERR 2
# define OPEN_ERR 3
# define COLOR_ERR 4
# define MAP_ERR 5
# define ARG_ERR 6
# define WIN_ERR 7
# define TEXTURE_LEN 64
# define MOVE_RANGE 5
# define VIEW_ANGLE 1.047197
# define TURN_SPEED 0.1

typedef struct	s_txt
{
	char		*name;
	char		*addr;
	void		*data;
	int			width;
	int			height;
	int			length;
	int			per_pix;
	int			endian;
}				t_txt;

typedef struct	s_map
{
	char		*name;
	char		**world_map;
	char		**ck_map;
	int			*len_list;
	int			map_len;
	int			map_width;
	int			wall_st_x;
	int			wall_st_y;
	int			win_x;
	int			win_y;
	int			flr_color;
	int			clg_color;
	int			max_win_x;
	int			max_win_y;
	int			ok_r;
	int			ok_no;
	int			ok_so;
	int			ok_we;
	int			ok_ea;
	int			ok_s;
	int			ok_f;
	int			ok_c;
	int			found_st_pos;
	int			comma;
	int			sp_num;
	int			sp_index;
	int			p_pos_st_x;
	int			p_pos_st_y;
	int			color;
	int			red;
	int			blue;
	int			green;
	double		height;
	double		prj_slice_height;
	double		wall_st_pos;
	double		len_to_wall;
	double		fish_len_to_wall;
}				t_map;

typedef struct	s_sp
{
	int			map_x;
	int			map_y;
	int			st_x;
	int			st_y;
	int			found_st_pos;
	int			color;
	double		hei_x;
	double		hei_y;
	double		angle;
	double		len_to_sp;
	double		f_len_to_sp;
	double		center_x;
}				t_sp;

typedef struct	s_player
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*addr;
	double		angle;
	double		ray_angle;
	int			dir_up;
	int			dir_down;
	int			dir_left;
	int			dir_right;
	double		view_angle;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		spin_x;
	double		spin_y;
	double		cur_x;
	double		cur_y;
	int			ready_to_go;
	double		h_cross_x;
	double		h_cross_y;
	double		v_cross_x;
	double		v_cross_y;
	int			ray_up;
	int			ray_down;
	int			ray_right;
	int			ray_left;
	double		h_wall_x;
	double		h_wall_y;
	double		v_wall_x;
	double		v_wall_y;
	t_sp		*sp_array;
	t_map		map;
	t_txt		info_no;
	t_txt		info_so;
	t_txt		info_ea;
	t_txt		info_we;
	t_txt		info_sp;
	double		h_const_x;
	double		h_const_y;
	double		v_const_x;
	double		v_const_y;
	int			is_touch_h;
	int			is_touch_v;
}				t_player;

char			*ft_strchar(char *s, char c);
void			ft_putstr_fd(char *s, int fd);
int				ft_strcmp(char *s1, char *s2);
int				g_map_data(t_map *map_info, t_player *p);
void			g_p_pos(t_player *p);
void			g_turn_dir(t_player *p);
void			g_map_len_width_sp(t_map *map_info);
void			g_txt(t_player *p, char dir, char *line);
void			g_len_to_sp(t_player *p, double cur_x, double cur_y);
void			g_background_color(t_map *map_info, char dir, char *line);
void			g_map(char *line, int *len, t_player *p, size_t len_line);
void			g_win_size(t_map *map_info, char *line);
void			g_len_to_wall(t_player *p, double cur_x, double cur_y);
void			d_background(t_player *p);
void			d_clg(t_player *p);
void			d_wld(t_player *p);
void			d_flr(t_player *p);
int				press_key(int key, t_player *p);
void			my_mlx_pixel_put(t_player *data, int x, int y, int color);
void			clear_player(t_player *p, double cur_x, double cur_y);
void			ray_dir(t_player *p);
void			find_v_cross(t_player *p, double fixed_ray_angle);
void			find_h_cross(t_player *p, double fixed_ray_angle);
void			clear_map(t_player *p);
void			compare_v_and_h(t_player *p);
void			ck_irregular(t_player *p, int *x, int *y, int *flag);
void			ck_map(t_player *p);
int				save_bmp(t_player *p);
void			error_quit(int errnum);
double			fix_angle(double angle);
void			set_value_v_h(t_player *p, double fixed_ray_angle, char c);
int				is_map(char *line);
int				is_map_data(char *line, size_t line_len);
void			fix_ray_angle(t_player *p);
void			skip_space(char *line, int *i);
double			modify_angle(double angle);
void			ck_info(t_map *map_info);
void			input_sp(t_player *p, char *line, int *len);
int				press_close_botton(int key, t_player *p);
void			d_sp(t_player *p, int *len_list, int index);
void			sort_sp(t_player *p, t_sp *sp_array);
void			init_map(t_map *map_info);
void			init_sp(t_map *map_info, t_player *p);
void			init_player(t_player *p);
void			init_txt(t_player *player, t_txt *texture);
void			init_sp_data(t_player *p, double *sp_angle
					, double p_start_angle, int index);
void			make_bmp(t_player p);
void			put_wall_line(t_player *p, int map_block_x, t_map map);
void			read_line(t_map *map_info, char *line, int *len, t_player *p);
void			add_zero(t_map *map_info, size_t len_line, int *len);
void			input_dir(t_map *map_info, char *line, int *len, int x);
void			input_map(t_map *map_info, char *line, size_t len_line
					, int *len);
int				find_h_point(t_player *p, double next_x, double next_y);
void			find_wall_h_point(t_player *p);
int				find_v_point(t_player *p, double next_x, double next_y);
void			next_v_point(t_player *p, double *next_x, double *next_y);
void			set_h_wall(t_player *p, double x, double y);
void			next_h_point(t_player *p, double *next_x, double *next_y);
void			set_v_wall(t_player *p, double x, double y);
void			first_wall_v_point(t_player *p);

#endif
