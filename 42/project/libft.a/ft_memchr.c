/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:38:03 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/24 17:03:24 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *ss = s;
	const unsigned char ch = c;

	while (n-- > 0)
		if (*ss == ch)
			return ((void *)s);
		ss++;
	return (NULL);
}
