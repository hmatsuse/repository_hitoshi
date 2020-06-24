/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 15:42:31 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/24 14:00:40 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	register char *dest = dst;
	register const char *ssrc = src;

    if (len != 0)
    {
        if (dest < ssrc)
        {
            register const char *t = dest + len;
            while (ssrc != t)
                *dest++ = *ssrc++;
        }
        else if (dest > ssrc)
        {
            register const char *t = dest;
            dest += len;
            ssrc += len;
            while (dest != t)
                *--dest = *--ssrc;
        }
    }
	return (dest);
}

// int main()
// {
//     // 変数定義
//     char buf1[] = "aabb";
//     char buf2[16];

//     // 配列の内容を表示
//     printf("配列の要素を表示(コピー前)。\n");
//     printf("buf1:%s\n", buf1);
//     printf("buf2:%s\n", buf2);

//     // メモリを上書きする
//     ft_memmove(buf2, buf1, 3);  // buf1の先頭3バイトをbuf2に上書きする
//     ft_memmove(&buf1[2], &buf1[0], 3);  // buf1の先頭3バイトをbuf1の3バイト目に上書きする

//     // 配列の内容を表示
//     printf("配列の要素を表示(コピー後)。\n");
//     printf("buf1:%s\n", buf1);
//     printf("buf2:%s\n", buf2);

//     return 0;
// }