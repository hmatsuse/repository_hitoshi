/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:49:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/09 21:27:22 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include "unistd.h"

int		get_next_line(int fd, char **line)
{
	static char		*buffer;

	if (!fd)
		return (NULL);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	buffer = read(fd, buffer, BUFFER_SIZE);
}
