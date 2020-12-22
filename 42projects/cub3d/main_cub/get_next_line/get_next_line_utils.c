/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:39:59 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/19 13:06:07 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	const char	*ptr;
	size_t		size;

	size = (ft_strlen(s1) + 1);
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	return (ft_strcpy((char *)ptr, s1));
}

char	*ft_strcpy(char *ptr, const char *src)
{
	size_t i;

	i = 0;
	while (src[i] != '\0')
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	size_t	i;
	size_t	s;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	s = 0;
	while (s1[s] != '\0')
		ptr[i++] = s1[s++];
	s = 0;
	while (s2[s] != '\0')
		ptr[i++] = s2[s++];
	ptr[i] = '\0';
	free((void *)s1);
	return (ptr);
}
