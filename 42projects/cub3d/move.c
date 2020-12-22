/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 21:03:07 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/23 21:55:04 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	move_front(t_data *img)
{
	// printf("map %c\n", worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)]);
	if (worldMap[(int)img->ply.posY][(int)(img->ply.posX + img->ply.dirX * img->ply.speed)] == 0)
	{
		img->ply.posX += img->ply.dirX * img->ply.speed;
		printf("img->ply.dirX:%f\n", img->ply.dirX);
		printf("img->ply.posX:%f\n", img->ply.posX);
	}
	if (worldMap[(int)(img->ply.posY + img->ply.dirY * img->ply.speed)][(int)img->ply.posX] == 0)
	{
		img->ply.posY += img->ply.dirY * img->ply.speed;
		printf("img->ply.dirY:%f\n", img->ply.dirY);
		printf("img->ply.posY:%f\n", img->ply.posY);
	}
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
	if (worldMap[(int)(img->ply.posY + img->ply.dirY * img->ply.speed)][(int)img->ply.dirX] == 0)
	{
		img->ply.dirY -= img->ply.dirY * img->ply.speed;
		printf("img->ply.dirY:%f\n", img->ply.dirY);
		printf("img->ply.posY:%f\n", img->ply.posY);
	}
}
