/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:50:15 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 14:30:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*result;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = 0;
	if (!(result = (char*)malloc((ft_strlen(s1)
						+ ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

static int		insert_and_save(char **line,
		char *concatline, char **save, int flg)
{
	int		len;

	if (flg)
		len = strlen(concatline);
	else
		len = count_until_nl(concatline);
	if (!len)
		*line = ft_strdup("");
	else
		*line = ft_substr(concatline, 0, len);
	if (*save)
		free(*save);
	*save = ft_substr(concatline + len, 1, ft_strlen(concatline) - len);
	return (1);
}

static int		free_all(char *save, char *concat_all, char *buf, int ret)
{
	if (save)
		free(save);
	if (concat_all)
		free(concat_all);
	if (buf)
		free(buf);
	return (ret);
}

static char		*str_concat(char *concat_all, char *buf, int read_result)
{
	char	*tmp;
	char	*substrtmp;

	substrtmp = ft_substr(buf, 0, read_result);
	tmp = ft_strjoin(concat_all, substrtmp);
	free(substrtmp);
	free(concat_all);
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	int				read_result;
	char			*concat_all;
	static char		*save[1024];

	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if ((read_result = read(fd, buf, BUFFER_SIZE)) < 0)
		return (free_all(buf, NULL, NULL, -1));
	buf[read_result] = '\0';
	concat_all = ft_strjoin(save[fd], buf);
	while (!ck_nl(concat_all))
	{
		if (!(read_result = read(fd, buf, BUFFER_SIZE)))
		{
			buf[read_result] = '\0';
			concat_all = str_concat(concat_all, buf, read_result);
			insert_and_save(line, concat_all, &save[fd], 1);
			return (free_all(save[fd], concat_all, buf, 0));
		}
		concat_all = str_concat(concat_all, buf, read_result);
	}
	insert_and_save(line, concat_all, &save[fd], 0);
	return (free_all(concat_all, buf, NULL, 1));
}
