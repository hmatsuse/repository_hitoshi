/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 12:07:07 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/08 13:19:05 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;
	size_t		size;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
	{
		if (!(ptr = ft_strdup("")))
			return (NULL);
		return (ptr);
	}
	if ((ft_strlen(s) - start) < len)
		size = ft_strlen(s) - (size_t)start;
	else
		size = len;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (size-- != 0)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
