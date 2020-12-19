/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:49:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/19 13:06:18 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		search(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		free_return(char *save, char *buf)
{
	free(save);
	free(buf);
	return (-1);
}

int		ft_read_sub(char **line, char *connect, char **save, char *buf)
{
	if (!(*line = ft_strdup(&connect[0])))
		return (free_return(*save, buf));
	*save = NULL;
	free_return(connect, buf);
	return (0);
}

int		fd_read(char **save, char **line, char *buf, int ret)
{
	char	*connect;
	int		index;

	buf[ret] = '\0';
	connect = ft_strjoin_free(*save, buf);
	if ((index = search(connect)) >= 0)
	{
		connect[index] = '\0';
		if (!(*line = ft_strdup(&connect[0])))
			return (free_return(*save, buf));
		if (!(*save = ft_strdup(&connect[index + 1])))
			return (free_return(*save, buf));
		free_return(connect, buf);
		return (1);
	}
	if ((ret == 0) && (index == -1))
		return (ft_read_sub(line, connect, save, buf));
	if (!(*save = ft_strdup(&connect[index + 1])))
		return (free_return(*save, buf));
	free(connect);
	return (-2);
}

int		get_next_line(int fd, char **line)
{
	static char	*save[1024];
	char		*buf;
	int			ret;
	int			r;

	if (fd < 0 || fd > 1023 || !line)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	while ((ret = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		r = fd_read(&save[fd], line, buf, ret);
		if (r >= 0)
			return (r);
		if (r == -1)
			break ;
	}
	return (-1);
}
