/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 17:07:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/06 17:44:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_flag *flag)
{
	if (flag->minus == 1 && flag->width > 1)
	{
		ft_putchar_fd_len('%', 1, flag);
		print_sp_or_zr(' ', flag->width - 1, flag);	
	}
	else if (flag->minus == 0 && flag->width > 1)
	{
		print_sp_or_zr(flag->zero_or_space, flag->width - 1, flag);	
		ft_putchar_fd_len('%', 1, flag);
	}
	else
		ft_putchar_fd_len('%', 1, flag);
}
