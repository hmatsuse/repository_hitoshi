/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:52:17 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 14:30:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*result;

	if (!s || len <= 0 || (int)start >= ft_strlen((char*)s))
		return (NULL);
	else
	{
		size = ft_strlen((char*)&s[start]);
		if (size < len)
			len = size;
		if (!(result = malloc((len + 1) * sizeof(char))))
			return (NULL);
		count = 0;
		while (count < len)
		{
			result[count] = s[start + count];
			count++;
		}
		result[count] = '\0';
		return (result);
	}
}

int			ft_strlen(char *s)
{
	int		count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char		*ft_strdup(const char *s)
{
	char	*result;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[size] != '\0')
		size++;
	if (!(result = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int			ck_nl(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (1);
	return (0);
}

int			count_until_nl(char *concatline)
{
	int i;

	i = 0;
	while (concatline[i] != '\n')
		i++;
	return (i);
}
