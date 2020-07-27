/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 14:38:03 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/30 18:57:35 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;
	unsigned char		ch;
	size_t				i;

	ss = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (n-- > 0)
	{
		if (ss[i] == ch)
			return ((void *)&ss[i]);
		i++;
	}
	return (NULL);
}
