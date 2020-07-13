/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:49:53 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/13 20:19:53 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		find(char *buff)
{
	size_t	i;

	i = 0;
	while(buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return(-1);
}

int		get_next_line(int fd, char **line)
{
	static char		*buffer;
	char			*buf;
	char			*tmp;
	char			*save;
	size_t			result;
	size_t			index;

	if (!fd)
		return (0);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	result = read(fd, buf, BUFFER_SIZE);
	if (!buffer)
		buffer = ft_strdup("");
	save = ft_strjoin(buffer, buf);
	if (find(save))
	{
		index = find(save);
		if (!(*line = ft_substr(save, 0, index)))
			return (-1);
		if (!(tmp = ft_strdup(save + index + 1)))
			return (-1);
		free(buf);
		buffer = tmp;
		return(1);
	}
	return (0);
}

// 使う変数

// 一週目
// 1,read関数=BUFFER_SIZE分readで読み込む,読み込んだ分をbufに格納
// 2,buf(2週目以降はbuff_size)に格納されている文字列をstrchrで\nがあるか探す
//   見つかれば\nまでの文字列をlineに格納し、\n以降の余った文字列をsaveに格納し、1をreturn
//   見つからなければbuffをsaveに格納し、1をreturn
// 3,読み込んだ文字が\0であればファイルすべて読み込んだと判断、それまでの文字列をlineに格納し、0をreturnしプログラム終了
// 2週目以降
// 3,readで読み込み、読み込んだ文字列をbuffに格納
//  （read関数は以前に読み込んだ文字列を記憶しているため指定しなくても以前読み込んだ最後の文字の次から読み込む）
// 4,saveに格納されている文字列とbuffを繋げてbuff_saveへ格納し2へ
