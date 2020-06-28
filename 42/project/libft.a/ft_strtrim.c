/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 16:59:50 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/28 21:52:19 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check(char const *set, char const s1)
{
	size_t i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*ptr;
	char			*start;
	char			*end;
	unsigned int	size;
	size_t			i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && check(set, s1[i]))
		i++;
	start = (char *)&s1[i];
	i = ft_strlen(s1) - 1;
	if (i != (size_t)-1)
		while (i >= 0 && check(set, s1[i]))
			i--;
	end = (char *)&s1[i];
	if (!*s1 || end == start)
		size = 2;
	else
		size = end - start + 2;
	if (!(ptr = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(ptr, start, size);
	return (ptr);
}
