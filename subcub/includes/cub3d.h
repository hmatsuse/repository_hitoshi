/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 14:11:52 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 03:32:12 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include <limits.h>
# include "get_next_line.h"

# define PI 3.14159265359
# define TRUE 1
# define FALSE 0
# define SAVE "--save"
# define CUB ".cub"
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
# define BLOCK_LEN 64
# define BLOCK_WIDTH 64
# define TEXTURE_LEN 64
# define MAX_RANGE 1000000
# define MOVE_RANGE 10
# define VIEW_ANGLE 1.047197
# define TURN_SPEED 0.261799387799149

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
	char		**check_map;
	int			map_len;
	int			map_width;
	int			start_wall_x;
	int			start_wall_y;
	int			win_x;
	int			win_y;
	int			floor_color;
	int			ceilling_color;
	int			max_win_x;
	int			max_win_y;
	int			found_start_pos;
	int			comma;
	int			sp_num;
	int			sp_index;
	int			*len_list;
	int			ok_r;
	int			ok_no;
	int			ok_so;
	int			ok_we;
	int			ok_ea;
	int			ok_s;
	int			ok_f;
	int			ok_c;
	int			p_start_pos_x;
	int			p_start_pos_y;
	int			color;
	int			red;
	int			blue;
	int			green;
	double		height;
	double		prj_slice_height;
	double		start_wall_position;
	double		len_to_wall;
	double		fish_len_to_wall;
}				t_map;

typedef struct	s_sp
{
	int			map_x;
	int			map_y;
	int			st_x;
	int			st_y;
	int			found_start_pos;
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
	double		cur_x;
	double		cur_y;
	double		spin_x;
	double		spin_y;
	int			ready_to_go;
	double		h_axis_x;
	double		h_axis_y;
	double		v_axis_x;
	double		v_axis_y;
	double		h_wall_x;
	double		h_wall_y;
	double		v_wall_x;
	double		v_wall_y;
	int			ray_up;
	int			ray_down;
	int			ray_left;
	int			ray_right;
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
	int			flg_hit_h;
	int			flg_hit_v;
}				t_player;

int				ft_strcmp(char *s1, char *s2);
void			ft_putstr_fd(char *s, int fd);
int				get_map_data(t_map *map_info, t_player *p);
void			get_p_pos(t_player *p);
void			draw_world(t_player *p);
int				press_key(int key, t_player *p);
void			my_mlx_pixel_put(t_player *data, int x, int y, int color);
void			clear_map(t_player *p);
void			draw_background(t_player *p);
void			clear_player(t_player *p, double cur_x, double cur_y);
void			draw_floor(t_player *p);
void			draw_ceiling(t_player *p);
void			get_turn_direction(t_player *p);
void			ray_direction(t_player *p);
void			search_h_axis(t_player *p, double fixed_ray_angle);
void			search_v_axis(t_player *p, double fixed_ray_angle);
void			compare_v_and_h(t_player *p);
double			fix_angle(double angle);
void			fix_ray_angle(t_player *p);
void			check_irregular(t_player *p, int *x, int *y, int *flag);
void			error_quit(int errnum);
char			*ft_strchar(char *s, char c);
double			modify_angle(double angle);
void			check_map(t_player *p);
int				save_bmp(t_player *p);
void			set_const_value(t_player *p, double fixed_ray_angle, char c);
void			get_map_len_width_sp(t_map *map_info);
int				is_map_data(char *line, size_t line_len);
int				is_map(char *line);
void			get_img(t_player *p, char dir, char *line);
void			skip_space(char *line, int *i);
void			get_background_color(t_map *map_info, char dir, char *line);
void			get_win_size(t_map *map_info, char *line);
void			get_map(char *line, int *len, t_player *p, size_t len_line);
void			check_info(t_map *map_info);
void			input_sprite(t_player *p, char *line, int *len);
void			sprite_init(t_map *map_info, t_player *p);
void			player_init(t_player *p);
void			map_init(t_map *map_info);
int				ft_close_botton(int key, t_player *p);
void			sp_data_init(t_player *p, double *sp_angle
					, double p_start_angle, int index);
void			draw_sprites(t_player *p, int *len_list, int index);
void			sort_sprite(t_player *p, t_sp *sp_array);
void			get_len_to_sprite(t_player *p, double cur_x, double cur_y);
void			make_bmp(t_player p);
void			draw_background(t_player *p);
void			get_len_to_wall(t_player *p, double cur_x, double cur_y);
void			put_wall_line(t_player *p, int map_block_x, t_map map);
void			img_init(t_player *player, t_txt *texture);
void			divide_line(t_map *map_info, char *line, int *len, t_player *p);
void			input_map(t_map *map_info, char *line, size_t len_line
					, int *len);
void			add_zero(t_map *map_info, size_t len_line, int *len);
void			input_dir(t_map *map_info, char *line, int *len, int x);
void			next_h_point(t_player *p, double *next_x, double *next_y);
int				founds_h_point(t_player *p, double next_x, double next_y);
void			find_wall_h_point(t_player *p);
void			set_h_wall(t_player *p, double x, double y);
void			set_v_wall(t_player *p, double x, double y);
void			first_wall_v_point(t_player *p);
int				founds_v_point(t_player *p, double next_x, double next_y);
void			next_v_point(t_player *p, double *next_x, double *next_y);

#endif
