/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamashi <syamashi@student.42.tokyo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 23:20:39 by syamashi          #+#    #+#             */
/*   Updated: 2020/07/08 23:40:23 by syamashi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	n;

	if (!s)
		return (0);
	n = 0;
	while (*s++ != '\0')
		n++;
	return (n);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*src;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	if (!(src = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	while (*s1)
		src[i++] = *s1++;
	j = 0;
	while (*s2)
		src[i + j++] = *s2++;
	src[i + j] = '\0';
	return (src);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if (*str++ == c)
			return (str - 1);
	}
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		ssz;
	int		n;

	ssz = ft_strlen(str);
	if (!(copy = malloc(sizeof(char) * (ssz + 1))))
		return (NULL);
	n = 0;
	if (!str)
	{
		*copy = '\0';
		return (copy);
	}
	while (*str)
		copy[n++] = *str++;
	copy[n] = '\0';
	return (copy);
}
