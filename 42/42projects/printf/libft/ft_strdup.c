/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:15:03 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/03 14:10:10 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
