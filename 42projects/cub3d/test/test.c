#include "mlx.h"
#include <unistd.h>
#include "cub3d.h"
#include <stdio.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     deal_key(int key, t_cub3d *cub3d)
{
    static int i;
    static int a;
    static int x;
    static int y;
    // int north;
    // int west;
    // int south;
    // int east;
    // w 上
    if (key == 13)
        y = 250 + --i;
    // s　下
    else if (key == 1)
        y = 250 + ++i;
    // d　右
    else if (key == 2)
        x = 250 + ++a;
    // a　左
    else if (key == 0)
        x = 250 + --a;
    mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, x, y, 0xFFFFFF);
    return (0);
}

int     main()
{
    t_cub3d cub3d;

    cub3d.mlx_ptr = mlx_init();
    cub3d.win_ptr = mlx_new_window(cub3d.mlx_ptr, 500, 500, "mlx 42");
    // mlx_pixel_put(cub3d.mlx_ptr, cub3d.win_ptr, 250, 250, 0xFFFFFF);
    mlx_hook(cub3d.win_ptr, 2, 0, deal_key, &cub3d);
    mlx_loop(cub3d.mlx_ptr);
}
