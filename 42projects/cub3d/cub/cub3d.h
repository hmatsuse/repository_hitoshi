#include "minilibx_mms_20200219/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>

#define KEY_W       13
#define KEY_S       1
#define KEY_A       0
#define KEY_D       2
#define KEY_LEFT    123
#define KEY_RIGHT   124
#define PI          3.1415926534
#define MOVE_RANGE  5
#define GRID        64

// int g_map[10][10] =
// {
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
//     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
// };

int	g_map[10][10] = 
{
	{0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 0, 0, 1},
	{0, 1, 1, 1, 1, 1, 1, 1}
};

typedef struct      s_game
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    void    *img_addr;

    int     img_bit_per_pix;
    int     img_endian;
    int     img_line_len;

    //player x
    double  px;
    //player y
    double  py;
    double  pa;
}                   t_game;
