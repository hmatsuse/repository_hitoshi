// #ifndef CUB3D_H
// # define CUB3D_H
#ifndef MAIN_H
# define MAIN_H

// # include "./libft/libft.h"
// # include "./get_next_line/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define WALL_N 0
# define WALL_S 1
# define WALL_W 2
# define WALL_E 3
# define N_TEXTURE "./textures/barrel.xpm"
# define S_TEXTURE "./textures/greystone.xpm"
# define W_TEXTURE "./textures/bluestone.xpm"
# define E_TEXTURE "./textures/colorstone.xpm"
# define COLOR_CEILING 0x00bce2e8
# define COLOR_FLOOR 0x00734e30
# define texHeight 64
# define texWidth 64

#define screenWidth 640
#define screenHeight 480

typedef struct			s_ray
{
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	int					map_x;
	int					map_y;
	int					pix;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				perp_wall_dist;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				*z_buffer;
}						t_ray;

typedef struct			s_map
{
	char				**map;
	const char			*map_name;
	int					width;
	int					height;
}						t_map;

typedef struct  s_p {
	double posX;
	double posY;
  	double dirX;
	double dirY;
  	double planeX;
	double planeY;
	double speed;
}               t_p;

typedef struct  s_ky {
	int fd;
	int bk;
	int rt;
	int lt;
}               t_ky;

typedef struct  s_data {
	void    	*mlx;
    void    	*mlx_win;
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	t_ky		key;
	t_p			ply;
}               t_data;


#define texWidth 64
#define texHeight 64
#define mapWidth 30
#define mapHeight 30

char worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	move_front(t_data *img);
void	move_back(t_data *img);

// typedef	struct			s_player
// {
// 	double				pos_x;
// 	double				pos_y;
// 	double				dir_x;
// 	double				dir_y;
// 	double				plane_x;
// 	double				plane_y;
// 	double				speed;
// 	double				rotate_speed;
// 	double				cam_height;
// }						t_player;

// typedef struct			s_key
// {
// 	int					front;
// 	int					back;
// 	int					left;
// 	int					right;
// 	int					turn_left;
// 	int					turn_right;
// }						t_key;

// typedef struct			s_img
// {
// 	void				*img_ptr;
// 	char				*addr;
// 	int					bits_per_pixel;
// 	int					line_length;
// 	int					endian;
// }						t_img;

// typedef struct			s_texture
// {
// 	void				*img_ptr;
// 	char				*addr;
// 	int					bits_per_pixel;
// 	int					line_length;
// 	int					endian;
// 	int					width;
// 	int					height;
// }						t_texture;

// typedef struct			s_sprite
// {
//   double x;
//   double y;
//   int texture;
// }						t_sprite;

// typedef	struct			s_window
// {
// 	void				*mlx_ptr;
// 	void				*win_ptr;
// 	int					width;
// 	int					height;
// 	int					save;			// nonused
// 	int					map_desc_found;	// nonused
// 	int					space_after_map_desc_found;	// nonused
// 	t_map				map;
// 	t_key				key;
// 	t_player			player;
// 	t_img				img;
// 	t_texture			textures[4];
// 	t_sprite			sprite;
// }						t_window;



#endif

