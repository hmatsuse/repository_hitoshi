//ヘッダー

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#define BUFS 1024
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int get_next_line(char **line);
#endif

//Cファイル
#include "get_next_line.h"

int ft_strlen(char *s)
{
	int len;
	
	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char *ft_strdup(char *s)
{
	char *copy;
	int len;
	int i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	copy = malloc(len + 1);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *copy;
	int i;
	int j;

	if (!s1 || !s2)
		return (NULL);
	copy = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	j = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		copy[i + j] = s2[j];
		j++;
	}
	copy[i + j] = '\0';
	return (copy);
}

int get_next_line(char **line)
{
	static char *save;
	char *buf;
	long ret;
	char *tmp;
	int i;

	if (save)
	{
		i = 0;
		while(save[i])
		{
			if (save[i] == '\n')
			{
				save[i] = '\0';
				*line = ft_strdup(save);
				tmp = save;
				save = ft_strdup(save + i + 1);
				free(tmp);
				return (1);
			}
			i++;
		}
	}
	buf = malloc(BUFS + 1);
	while ((ret = read(0, buf, BUFS)))
	{
		if (ret < 0)//読み込み失敗した場合
		{
			free(buf);
			return (-1);
		}
		i = 0;
		buf[ret] = '\0';
		if (!save)
			save = ft_strdup("");
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				buf[i] = '\0';
				*line = ft_strjoin(save, buf);
				tmp = save;
				save = ft_strdup(buf + i + 1);
				free(tmp);
				free(buf);
				return (1);
			}
			i++;
		}
		tmp = save;
		save = ft_strjoin(save, buf);
		free(tmp);
	}
	if (!save)
		*line = ft_strdup("");//空のファイルを渡された場合、ここ。
	else
		*line = ft_strdup(save);
	free(buf);
	free(save);
	save = NULL;
	return (0);
}

