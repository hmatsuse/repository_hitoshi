/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 05:41:36 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 04:46:55 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_map(char *line)
{
	int		i;

	i = 0;
	while (ft_strchar("012 NESW", line[i]))
		i++;
	if (0 == line[i])
		return (TRUE);
	else
		return (FALSE);
}

int		is_map_data(char *line, size_t line_len)
{
	if (line[0] == 'R' && line[1] == ' ')
		return (FALSE);
	else if (line[0] == 'N' && line[1] == 'O')
		return (FALSE);
	else if (line[0] == 'S' && line[1] == 'O')
		return (FALSE);
	else if (line[0] == 'W' && line[1] == 'E')
		return (FALSE);
	else if (line[0] == 'E' && line[1] == 'A')
		return (FALSE);
	else if (line[0] == 'S' && line[1] == ' ')
		return (FALSE);
	else if (line[0] == 'F' && line[1] == ' ')
		return (FALSE);
	else if (line[0] == 'C' && line[1] == ' ')
		return (FALSE);
	else if (line_len == 0)
		return (FALSE);
	else if (is_map(line))
		return (TRUE);
	else
		return (FALSE);
}
