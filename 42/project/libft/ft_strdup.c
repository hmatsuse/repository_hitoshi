/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 20:15:03 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/26 20:56:25 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*ptr;
	size_t		size;

	size = (ft_strlen(s1) + 1);
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	return (ft_strcpy((char *)ptr, s1));
}
