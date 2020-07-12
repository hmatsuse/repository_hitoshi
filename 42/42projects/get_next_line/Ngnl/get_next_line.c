/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukada <nfukada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 21:34:07 by nfukada           #+#    #+#             */
/*   Updated: 2020/07/04 13:13:51 by nfukada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_newline(char *str, size_t *index)
{
	*index = 0;
	if (!str)
	{
		return (0);
	}
	while (str[*index])
	{
		if (str[*index] == '\n')
		{
			return (1);
		}
		(*index)++;
	}
	return (0);
}

int			free_and_return(char **line, char **buffer, int return_value)
{
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	if (buffer)
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (return_value);
}

int			read_fd(int fd, char **line, char **fd_buffer, char *buffer)
{
	ssize_t	result;
	size_t	index;

	while ((result = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[result] = '\0';
		if (has_newline(buffer, &index))
		{
			buffer[index] = '\0';
			if (!append_line(line, buffer))
				free_and_return(line, &buffer, STATUS_ERROR);
			if (!(*fd_buffer = ft_strdup(buffer + index + 1)))
				free_and_return(line, &buffer, STATUS_ERROR);
			return (free_and_return(NULL, &buffer, STATUS_LINE));
		}
		else
		{
			if (!append_line(line, buffer))
				free_and_return(line, &buffer, STATUS_ERROR);
		}
	}
	return (free_and_return(NULL, &buffer, result));
}

int			get_next_line(int fd, char **line)
{
	static char	*fd_buffer;
	char		*buffer;
	char		*tmp;
	size_t		index;

	if (fd < 0 || fd >= OPEN_MAX || !line)
		return (STATUS_ERROR);
	if (has_newline(fd_buffer, &index))
	{
		fd_buffer[index] = '\0';
		if (!(*line = ft_strdup(fd_buffer)))
			return (STATUS_ERROR);
		if (!(tmp = ft_strdup(fd_buffer + index + 1)))
			free_and_return(line, NULL, STATUS_ERROR);
		free(fd_buffer);
		fd_buffer = tmp;
		return (STATUS_LINE);
	}
	if (!(*line = ft_strdup(fd_buffer)))
		return (STATUS_ERROR);
	free_and_return(NULL, &fd_buffer, 0);
	if (!(buffer = (char *)malloc(BUFFER_SIZE + 1)))
		return (free_and_return(line, NULL, STATUS_ERROR));
	return (read_fd(fd, line, &fd_buffer, buffer));
}
