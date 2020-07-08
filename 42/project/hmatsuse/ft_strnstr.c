/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:02:44 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/08 13:09:37 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*ptr;
	size_t		i;

	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		if (*haystack == *needle)
		{
			ptr = haystack;
			while (*haystack++ == needle[i] && len > 0)
			{
				if (needle[i + 1] == '\0')
					return ((char *)ptr);
				len--;
				i++;
			}
		}
		haystack++;
		len--;
	}
	return (NULL);
}
