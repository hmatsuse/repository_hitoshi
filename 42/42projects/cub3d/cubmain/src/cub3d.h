#ifndef CUB3D_H
#define CUB3D_H
#include "../minilibx_mms_20200219/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>

#define KEY_W       13
#define KEY_S       1
#define KEY_A       0
#define KEY_D       2
#define KEY_LEFT    123
#define KEY_RIGHT   124
#define PI          3.1415926534
#define MOVE_RANGE  5
#define GRID        64
#define WIN_WID     640
#define WIN_HEI     256
#define FOV         90
#define BUFFER_SIZE 	1024

int	map[4][10] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1},
};

// typedef struct s_r
// {
//     int r[2];
// }               t_r;

// typedef struct			s_win_size
// {
// 	int					index;
// 	int					size_x;
// 	int					size_y;
// 	int					element_1;
// 	int					element_2;
// }						t_win_size;

typedef struct s_wall_texture
{
    char *path;
}               t_wall_texture;

typedef struct s_color
{
    int color[3];
}               t_color;

typedef struct s_map
{
    char **map;
}               t_map;

typedef struct      s_file
{
    char *file_name;
    // char **file;
}                   t_file;

typedef struct		s_indent
{
	int indent;
}					t_indent;

typedef struct      s_game
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    void    *img_addr;
    int     img_bit_per_pix;
    int     img_endian;
    int     img_line_len;
	int 	win_wid;
	int 	win_hei;
	int		too_big;

    // t_r     r_info;
    t_wall_texture		no_info;
    t_wall_texture		so_info;
    t_wall_texture		we_info;
    t_wall_texture		ea_info;
    t_wall_texture		s_info;
    t_color        		f_info;
    t_color           	c_info;
	t_indent			indent_info;
    t_map   map_info;
    t_file  file_info;

    //player x
    double  px;
    //player y
    double  py;
    double  pa;
}                   t_game;


int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *ptr, const char *src);
char	*ft_strjoin_free(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

#endif
