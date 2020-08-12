#include "mlx.h"
#include <unistd.h>
#include "cub3d.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     deal_key(int key, t_cub3d *cub3d)
{
    ft_putchar('X');
    mlx_pixel_put(cub3d->mlx_ptr, cub3d->win_ptr, 200, 200, 0xFFFFFF);
    return (0);
}

int     main()
{
    t_cub3d cub3d;

    cub3d.mlx_ptr = mlx_init();
    cub3d.win_ptr = mlx_new_window(cub3d.mlx_ptr, 500, 500, "mlx 42");
    mlx_pixel_put(cub3d.mlx_ptr, cub3d.win_ptr, 250, 250, 0xFFFFFF);
    mlx_key_hook(cub3d.win_ptr, deal_key, &cub3d);
    mlx_loop(cub3d.mlx_ptr);
}
