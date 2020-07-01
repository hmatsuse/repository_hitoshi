/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 15:36:27 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/25 17:59:27 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p = NULL;

	while (1)
	{
		if (*s == c)
			p = s;
		if (*s == '\0')
			break ;
		s++;
	}
	return ((char *)p);
}
