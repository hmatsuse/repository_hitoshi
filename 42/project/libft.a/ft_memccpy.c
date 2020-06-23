/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:20:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/23 17:44:48 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n)
{
	register char *dest = dst;
	register const char *ssrc = src;
	const unsigned char ch = c;
	register const char *t = ssrc + n;

	while (ssrc != t)
	{
		*dest++ = *ssrc++;
		if (*ssrc == ch)
			return(dest);
	}
	return(NULL);
}

int		main(void)
{
	char buf[] = "ABCDEFGHIJ";
	char buf2[] = "123456789";

	ft_memccpy(buf, buf2, 'k', 7);
	printf("copied buf = %s\n", buf);

	return (0);
}
