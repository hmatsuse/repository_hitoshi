/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:02:44 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/16 18:04:21 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlelen;

	needlelen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0' && len >= needlelen)
	{
		if (*haystack == *needle)
		{
			if (ft_strncmp(haystack, needle, needlelen) == 0)
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}


int		main()
{
	char s[] = "ajbsdchbahcd";
	char look[] = "ajbsdchbahcdajbsdchbahcd";

	printf("%s\n", ft_strnstr(s, look, 10000000));
}
