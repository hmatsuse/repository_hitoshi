/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_diu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:09:39 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/08 18:47:31 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_minus(t_flag *flag)
{
	if (flag->diu_is_minus == 1)
	{
		ft_putchar_fd_len('-', 1, flag);
		return (1);
	}
	return (0);
}

void	put_minus_diu(char *ap_tmp, t_flag *flag)
{
	// if (put_minus(flag) == 1)
	// 	flag->sp_zr_len_dot -= 1;
	if (flag->dot == 1)
	{
		print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr(ap_tmp, flag->print_len, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
	else
	{
		ft_putnstr(ap_tmp, flag->print_len, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
}

void	put_diu(char *ap_tmp, t_flag *flag)
{
	if (flag->dot == 1)
	{
		put_minus(flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr(ap_tmp, flag->print_len, flag);
	}
	else
	{
		put_minus(flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		ft_putnstr(ap_tmp, flag->print_len, flag);
	}
}

void	diu(char *ap_tmp, t_flag *flag)
{
	if (flag->dot == 1 && flag->dot_width == 0 && flag->tmp == 0)
	{
		print_sp_or_zr(' ', flag->width, flag);
		return ;
	}
	if (flag->minus == 1 && flag->sp_zr_len > 0)
		put_minus_diu(ap_tmp, flag);
	else if (flag->minus == 0 && flag->sp_zr_len > 0)
		put_diu(ap_tmp, flag);
	else
	{
		put_minus(flag);
		ft_putnstr(ap_tmp, flag->print_len, flag);
	}
	
}
