/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:49:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/15 18:35:54 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		search(char	*buf)
{
	int	i;

	i = 0;
	while(buf[i] != '\0')
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		free_return(char *buffer, char *buf)
{
	free(buffer);
	free(buf);
	return (-1);
}

// int		check(char **buffer, char **line)
// {
// 	int		index;
// 	char	*save;
// 	char	*tmp;

// 	while ((index = search(*buffer)) >= 0)
// 	{
// 		(*buffer)[index] = '\0';
// 		if (!(*line = ft_substr(*buffer, 0, index)))
// 			return (-1);
// 		if (!(tmp = ft_strdup(*buffer + index + 1)))
// 			return (-1);
// 		*buffer = tmp;
// 		return (1);
// 	}
// 	*line = ft_strdup(*buffer);
// 	return (0);
// }

int		fd_read(int fd, char **buffer, char **line)
{
	char	*buf;
	char	*save;
	int		index;
	int		ret;
	
	if(!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[ret] = '\0';
		save = ft_strjoin(*buffer, buf);
		if ((index = search(save)) >= 0)
		{
			save[index] = '\0';
			if (!(*line = ft_substr(save, 0, index)))
				return (free_return(*buffer, buf));
			if (!(*buffer = ft_strdup(&save[index + 1])))
				return (free_return(*buffer, buf));
			return (1);
		}
		if ((ret == 0) && (index == -1))
			return (0);
		*buffer = ft_strdup(&save[0]);
		free(save);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer;

	if (!buffer)
		buffer = ft_strdup("");
	return (fd_read(fd, &buffer, line));
}
