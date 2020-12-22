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

# define ARG_ERR 6
# define TEXTURE_ERR 1
# define MALLOC_ERR 2
# define OPEN_ERR 3
# define COLOR_ERR 4
# define MAP_ERR 5
# define PI 3.14159265359
# define DISTANCE_TO_PROJECTION_PLANE 277
# define VIEW_ANGLE 1.047197
# define FALSE 0
# define TRUE 1
# define BLOCK_WIDTH 64
# define BLOCK_LEN 64

typedef struct	s_sprite
{
	double		len_to_sprite;
	double		fish_len_to_sprite;
	double		angle;
	double		center_x;
	double		y_height;
	double		x_height;
	int			start_x;
	int			start_y;
	int			found_start_pos;
	int			map_x;
	int			map_y;
	int			color;
}				t_sprite;

typedef struct	s_map
{
	char		*name;
	char		**world_map;
	char		**map_check;
	char		**save_ptr;
	int			map_len;
	int			map_width;
	int			tmp;
	double		len_to_wall;
	double		fish_len_to_wall;
	int			start_wall_x;
	int			start_wall_y;
	int			win_x;
	int			win_y;
	int			floor_color;
	int			ceilling_color;
	int			max_win_x;
	int			max_win_y;
	int			found_start_pos;
	int			red;
	int			green;
	int			blue;
	int			comma;
	int			sp_num;
	int			sp_index;
	int			*len_list;
	int			found_r;
	int			found_no;
	int			found_so;
	int			found_we;
	int			found_ea;
	int			found_s;
	int			found_f;
	int			found_c;
	int			p_init_pos_x;
	int			p_init_pos_y;
	int			color;
	double		height;
	double		prj_slice_height;
	double		start_wall_position;
}				t_map;

typedef struct	s_texture
{
	char		*file_name;
	void		*data;
	int			width;
	int			height;
	char		*addr;
	int			per_pixel;
	int			length;
	int			endian;
}				t_texture;

typedef struct	s_player
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		current_x;
	double		current_y;
	double		spin_x;
	double		spin_y;
	double		angle;
	double		ray_angle;
	double		view_angle;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			is_ready;
	double		scaling;
	int			mini_len_to_wall;
	int			is_facing_up;
	int			is_facing_down;
	int			is_facing_left;
	int			is_facing_right;
	int			ray_is_facing_up;
	int			ray_is_facing_down;
	int			ray_is_facing_left;
	int			ray_is_facing_right;
	double		horizontal_intersection_x;
	double		horizontal_intersection_y;
	double		vertical_intersection_x;
	double		vertical_intersection_y;
	double		hit_wall_x_for_horizontal;
	double		hit_wall_y_for_horizontal;
	double		hit_wall_x_for_vertical;
	double		hit_wall_y_for_vertical;
	double		const_x_for_horizontal;
	double		const_y_for_horizontal;
	double		const_x_for_vertical;
	double		const_y_for_vertical;
	int			is_hit_horizontal;
	int			is_hit_vertical;
	int			is_hit_sprite;
	t_map		map;
	t_texture	tex_no;
	t_texture	tex_so;
	t_texture	tex_ea;
	t_texture	tex_we;
	t_texture	tex_sprite;
	t_sprite	*sp_list;
}				t_player;

void		ft_putstr_fd(char *s, int fd);
void		err_exit(int num);
char		*ft_strchar(char *s, char c);
void		skip_space(char *line, int *i);
void    	get_texture(t_player *p, char dir, char *line);
int			is_map(char *line);
void		check_info(t_map *map_info);
void		my_mlx_pixel_put(t_player *p, int x, int y, int color);
void    	check_map(t_player *p);
void		put_floor(t_player *p);
void		put_ceilling(t_player *p);
void		get_turn_dir(t_player *p);

#endif
