/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:40:04 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 04:47:37 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	header_init(char *cont, int width, int height)
{
	int		size;

	size = width * height * 3 + 54;
	*(unsigned int *)cont = (unsigned int)'B';
	*(unsigned int *)(cont + 1) = (unsigned int)'M';
	*(unsigned int *)(cont + 2) = (unsigned long)size;
	*(unsigned int *)(cont + 6) = (unsigned int)0;
	*(unsigned int *)(cont + 8) = (unsigned int)0;
	*(unsigned int *)(cont + 10) = (unsigned int)54;
	*(unsigned int *)(cont + 14) = (unsigned long)40;
	*(unsigned int *)(cont + 18) = (long)width;
	*(unsigned int *)(cont + 22) = (long)-height;
	*(unsigned int *)(cont + 26) = (unsigned int)1;
	*(unsigned int *)(cont + 28) = (unsigned int)24;
	*(unsigned int *)(cont + 30) = (unsigned long)0;
	*(unsigned int *)(cont + 34) = (unsigned long)(size - 54);
	*(unsigned int *)(cont + 38) = (long)0;
	*(unsigned int *)(cont + 42) = (long)0;
	*(unsigned int *)(cont + 46) = (unsigned long)0;
	*(unsigned int *)(cont + 50) = (unsigned long)0;
}

void	header_data(t_player *p, char *cont, int width, int height)
{
	char	*color;
	int		now;
	int		utils[3];

	header_init(cont, width, height);
	now = 54;
	utils[1] = 0;
	while (utils[1] < height)
	{
		utils[0] = 0;
		while (utils[0] < width)
		{
			color = p->addr + utils[0] * (p->bits_per_pixel / 8)\
			+ (utils[1] * p->line_length);
			*(unsigned char *)(cont + now++) = *(unsigned char *)color++;
			*(unsigned char *)(cont + now++) = *(unsigned char *)color++;
			*(unsigned char *)(cont + now++) = *(unsigned char *)color++;
			utils[0]++;
		}
		utils[2] = width % 4;
		while (utils[2]--)
			*(cont + now++) = 0;
		utils[1]++;
	}
}

int		save_bmp(t_player *p)
{
	int		fd;
	char	*cont;
	int		padding;

	fd = open("bitmap.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	if (fd < 0)
		error_quit(OPEN_ERR);
	padding = (p->map.win_x * 3) % 4;
	cont = malloc((p->map.win_x + padding) * p->map.win_y * 3 + 54 + 1);
	header_data(p, cont, p->map.win_x, p->map.win_y);
	write(fd, cont, (p->map.win_x + padding) * p->map.win_y * 3 + 54);
	close(fd);
	exit(0);
	return (0);
}

void	make_bmp(t_player p)
{
	p.img = mlx_new_image(p.mlx_ptr, p.map.win_x, p.map.win_y);
	p.addr = mlx_get_data_addr(p.img, &p.bits_per_pixel
		, &p.line_length, &p.endian);
	get_p_pos(&p);
	check_map(&p);
	d_background(&p);
	d_wld(&p);
	save_bmp(&p);
}
