/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maincub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 15:17:32 by miwaura           #+#    #+#             */
/*   Updated: 2020/08/23 22:50:04 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// #define screenWidth 640
// #define screenHeight 480

void ply(t_data *img)
{
	img->ply.posX = 22;
	img->ply.posY = 12;
  	img->ply.dirX = -1;
	img->ply.dirY = 0;
  	img->ply.planeX = 0;
	img->ply.planeY = 0.66;
	// img->ply.speed = 0.03;
	img->ply.speed = 0.16;
}

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	move_front(t_data *img)
{
	// printf("map %c\n", worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)]);
	if (worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)] == 0)
	{
		img->ply.posX += img->ply.dirX * img->ply.speed;
		printf("img->ply.dirX:%f\n", img->ply.dirX);
		printf("img->ply.posX:%f\n", img->ply.posX);
	}
	// if (worldMap[(int)(img->ply.posY + img->ply.dirY * img->ply.speed)]	[(int)img->ply.posX] == 0)
	// {
	// 	img->ply.posY += img->ply.dirY * img->ply.speed;
	// 	printf("img->ply.dirY:%f\n", img->ply.dirY);
	// 	printf("img->ply.posY:%f\n", img->ply.posY);
	// }
	// printf("img->ply.posX %f\n", img->ply.posX);
}

void	move_back(t_data *img)
{
	if (worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)] == 0)
	{
		img->ply.posX -= img->ply.dirX * img->ply.speed;
		printf("img->ply.dirX:%f\n", img->ply.dirX);
		printf("img->ply.posX:%f\n", img->ply.posX);
	}
	// if (worldMap[(int)(img->ply.posY + img->ply.dirY * img->ply.speed)][(int)img->ply.posX] == 0)
	// {
	// 	img->ply.dirY -= img->ply.dirY * img->ply.speed;
	// 	printf("img->ply.dirY:%f\n", img->ply.dirY);
	// 	printf("img->ply.posY:%f\n", img->ply.posY);
	// }
}

void	move_right(t_data *img)
{
	if (worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)] == 0)
	{
		img->ply.posY -= img->ply.dirX * img->ply.speed;
		printf("img->ply.dirX:%f\n", img->ply.dirX);
		printf("img->ply.posY:%f\n", img->ply.posY);
	}
}

void	move_left(t_data *img)
{
	if (worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)] == 0)
	{
		img->ply.posY += img->ply.dirX * img->ply.speed;
		printf("img->ply.dirX:%f\n", img->ply.dirX);
		printf("img->ply.posY:%f\n", img->ply.posY);
	}
}

int		key_pressed(int keycode, t_data *img)
{
	// static int i;
    // static int a;
    // static int x;
    // static int y;
	printf("--------------------------\n");
	printf("-%d-\n", keycode);
	// if (keycode == KEY_ESC)
	// 	exit(0);
	if (keycode == KEY_W)
	{
		img->key.fd = 1;
        // img->ply.posY -= 0.001;
		// exit(0);
	}
	else if (keycode == KEY_S)
	{
		img->key.fd = 2;
        // img->ply.posX -= 0.001;
		// exit(0);
	}
	else if (keycode == KEY_D)
	{
		img->key.fd = 3;
        // img->ply.posY += 0.001;
		// exit(0);
	}
	else if (keycode == KEY_A)
	{
		img->key.fd = 4;
        // img->ply.posX += 0.001;
		// exit(0);
	}
	// printf("img->ply.posY %f\n", img->ply.posY);
	// printf("img->ply.posX %f\n", img->ply.posX);
    // mlx_pixel_put(img->mlx, img->mlx_win, img->ply.dirX, img->ply.dirY, 0xFFFFFF);
	return (0);
}

int	render_next_frame(void *p)
{
	t_data  *img;

	img = (t_data *)p;
	int x = 0;
	int h = screenHeight;
	int w = screenWidth;
	while (x < screenWidth)
	{
		// ply(img);
		double cameraX = 2 * x / (double)w - 1; //x-coordinate in camera space
      	double rayDirX = img->ply.dirX + img->ply.planeX * cameraX;
      	double rayDirY = img->ply.dirY + img->ply.planeY * cameraX;
      	//which box of the map we're in
      	int mapX = (int)(img->ply.posX);
      	int mapY = (int)(img->ply.posY);
		   //length of ray from current position to next x or y-side
      	double sideDistX;
      	double sideDistY;

       	//length of ray from one x or y-side to next x or y-side
      	double deltaDistX = fabs(1 / rayDirX);
      	double deltaDistY = fabs(1 / rayDirY);
      	double perpWallDist;

      	//what direction to step in x or y-direction (either +1 or -1)
      	int stepX;
      	int stepY;

      	int hit = 0; //was there a wall hit?
      	int side; //was a NS or a EW wall hit?
      	//calculate step and initial sideDist
		if(rayDirX < 0)
      	{
        	stepX = -1;
       		sideDistX = (img->ply.posX- mapX) * deltaDistX;
      	}
      	else
      	{
        	stepX = 1;
        	sideDistX = (mapX + 1.0 - img->ply.posX) * deltaDistX;
      	}
      	if(rayDirY < 0)
      	{
       		stepY = -1;
        	sideDistY = (img->ply.posY - mapY) * deltaDistY;
      	}
     	 else
      	{
        	stepY = 1;
        	sideDistY = (mapY + 1.0 - img->ply.posY) * deltaDistY;
      	}
      //perform DDA
      	while (hit == 0)
      	{
        	//jump to next map square, OR in x-direction, OR in y-direction
        	if(sideDistX < sideDistY)
        	{
         	 	sideDistX += deltaDistX;
          		mapX += stepX;
         	 	side = 0;
        	}
        	else
        	{
				sideDistY += deltaDistY;
        	  	mapY += stepY;
        	  	side = 1;
        	}
			if(worldMap[mapX][mapY] > 0) hit = 1;
		}
		if(side == 0) 
			perpWallDist = (mapX - img->ply.posX+ (1 - stepX) / 2) / rayDirX;
      	else          
		  	perpWallDist = (mapY - img->ply.posY + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(h / perpWallDist);

      	//calculate lowest and highest pixel to fill in current stripe
      	int drawStart = -lineHeight / 2 + h / 2;
      	if(drawStart < 0)
		  	drawStart = 0;
      	int drawEnd = lineHeight / 2 + h / 2;
      	if(drawEnd >= h)
		  	drawEnd = h - 1;
		int color;
		if (worldMap[mapX][mapY] == 1)
		{
			color = 0x00ff00;//green
		} 
		else if(worldMap[mapX][mapY] == 2)
		{
			color = 0xffff00;//yellow
		}
		else if(worldMap[mapX][mapY] == 3)
		{
			color = 0x0000ff;//blue
		}
		else if(worldMap[mapX][mapY] == 4)
		{
			color = 0xff00ff;//pink
		}
		if(side == 1)
			color = color / 2;
		int y = drawStart;
		while (y++ < drawEnd)
		{
			my_mlx_pixel_put(img, x, y, color);
		}
		y = 0;
		while (y++ < drawStart)
		{
			my_mlx_pixel_put(img, x, y, 0xace6aa);
		}
		y = drawEnd;
		while (y++ < screenHeight - 1)
		{
			my_mlx_pixel_put(img, x, y, 0x9eb3b3);
		}
		x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	if (img->key.fd == 1)
		move_front(img);
	else if (img->key.fd == 2)
		move_back(img);
	else if (img->key.fd == 3)
		move_right(img);
	else if (img->key.fd == 4)
		move_left(img);
	img->key.fd = 0;
	// printf("TEST\n");
	return 0;
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
    t_data  img;

    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, screenWidth, screenHeight, "Hello world!");
	img.img = mlx_new_image(img.mlx, screenWidth, screenHeight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	ply(&img);
	// mlx_hook(img.mlx_win, 2, 1L<<0, key_pressed, &img);
	mlx_hook(img.mlx_win, 2, 0, key_pressed, &img);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	mlx_loop(img.mlx);
	return (0);
}
