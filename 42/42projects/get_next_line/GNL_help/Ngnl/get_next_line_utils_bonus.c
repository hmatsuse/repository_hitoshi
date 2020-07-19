/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukada <nfukada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 00:34:03 by nfukada           #+#    #+#             */
/*   Updated: 2020/07/04 01:31:10 by nfukada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*dup;

	len = (s1 != NULL ? ft_strlen(s1) : 0);
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup != NULL)
	{
		i = 0;
		while (i < len)
		{
			dup[i] = s1[i];
			i++;
		}
		dup[i] = '\0';
	}
	return (dup);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int		append_line(char **line, const char *src)
{
	size_t	line_len;
	size_t	src_len;
	char	*tmp_line;

	line_len = ft_strlen(*line);
	src_len = ft_strlen(src);
	if (!(tmp_line = ft_strdup(*line)))
	{
		return (0);
	}
	free(*line);
	*line = (char *)malloc((line_len + src_len + 1) * sizeof(char));
	if (*line == NULL)
	{
		return (0);
	}
	ft_strncpy(*line, tmp_line, line_len + 1);
	ft_strncpy(*line + line_len, src, src_len + 1);
	free(tmp_line);
	return (1);
}
