/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:38:03 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 12:17:08 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ss;
	char ch;

	ss = s;
	ch = c;
	while (n-- > 0)
	{
		if (*ss == ch)
			return ((void *)s);
		ss++;
	}
	return (NULL);
}
