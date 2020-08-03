/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_cul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:39:28 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/03 21:05:49 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	adress_cul(unsigned long tmp, char *src, t_flag *flag)
{
	int	j;

	j = tmp % 16;
	if (tmp >= 16)
	{
		tmp = tmp / 16;
		adress_cul(tmp, src, flag);
	}
	ft_putchar_fd_len(src[j], 1, flag);
}
