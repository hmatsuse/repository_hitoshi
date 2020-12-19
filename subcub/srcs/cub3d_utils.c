/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 14:22:41 by knagashi          #+#    #+#             */
/*   Updated: 2020/12/16 22:38:47 by knagashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	compare_v_and_h(t_player *player)
{
	double	h_dis;
	double	v_dis;

	player->flg_hit_h = FALSE;
	player->flg_hit_v = FALSE;
	h_dis = hypot(fabs(player->h_wall_x - player->cur_x),
			fabs(player->h_wall_y - player->cur_y));
	v_dis = hypot(fabs(player->v_wall_x - player->cur_x),
			fabs(player->v_wall_y - player->cur_y));
	player->map.len_to_wall = fmin(h_dis, v_dis);
	if (h_dis < v_dis)
		player->flg_hit_h = TRUE;
	else
		player->flg_hit_v = TRUE;
}

void	skip_space(char *line, int *i)
{
	while (ft_strchar(" ", line[*i]))
		(*i)++;
}

char	*ft_strchar(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, &*s, 1);
			s++;
		}
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (0);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (1);
	else
		return (0);
}
