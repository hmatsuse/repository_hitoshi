/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 20:32:31 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/22 20:32:31 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	register char *bbuf1 = dst;
	register const char *bbuf2 = src;

	while (n-- > 0)
		*bbuf1++ = *bbuf2++;
	return (dst);
}

// int		main(void)
// {
// 	char buf[] = "ABCDEFG";
// 	char buf2[] = "1ee3456789";

// 	ft_memcpy(buf, buf2, 4);
// 	printf("copied buf = %s\n", buf);

// 	return (0);
// }
