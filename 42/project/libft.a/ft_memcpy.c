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
	register const char *t = bbuf2 + n;

	while (bbuf2 != t)
		*bbuf1++ = *bbuf2++;
	return (bbuf1);
}

int		main(void)
{
	char buf[] = "ABCDEFG";
	char buf2[] = "1ee3456789";

	ft_memcpy(buf, buf2, 4);
	printf("copied buf = %s\n", buf);

	return (0);
}
