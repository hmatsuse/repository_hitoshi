/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:42:32 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/03 16:46:29 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sp_or_zr(char	sp_or_zr, int sp_zr_len)
{
	int i;

	i = 0;
	while (i++ != sp_zr_len)
		ft_putchar_fd(sp_or_zr, 1);
}

void	print_c(char **format, va_list ap, t_flag *flag)
{
	int		sp_zr_len;

	sp_zr_len = flag->width - 1;
	if (flag->minus == 1 && sp_zr_len > 1)
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		print_sp_or_zr(flag->zero_or_space, sp_zr_len);
	}
	else if (flag->minus == 0 && sp_zr_len > 1)
	{
		print_sp_or_zr(flag->zero_or_space, sp_zr_len);
		ft_putchar_fd(va_arg(ap, int), 1);
	}
	else
		ft_putchar_fd(va_arg(ap, int), 1);
}

void	print_s(char **format, va_list ap, t_flag *flag)
{
	char	*ap_tmp;
	int		print_len;
	int		sp_zr_len;

	ap_tmp = va_arg(ap, char *); 
	if (flag->dot == 1)
		print_len = ft_min((int)ft_strlen(ap_tmp), flag->dot_width);
	else
		print_len = (int)ft_strlen(ap_tmp);
	sp_zr_len = flag->width - print_len;
	if (flag->minus == 1 && sp_zr_len > 0)
	{
		ft_putnstr(ap_tmp, print_len);
		print_sp_or_zr(flag->zero_or_space, sp_zr_len);
	}
	else if (flag->minus == 0 && sp_zr_len > 0)
	{
		print_sp_or_zr(flag->zero_or_space, sp_zr_len);
		ft_putnstr(ap_tmp, print_len);
	}
	else
		ft_putnstr(ap_tmp, print_len);
}

void	print_d(char **format, va_list ap, t_flag *flag)
{
	char		*ap_tmp;
	int			ap_tmp_len;
	int			sp_zr_len;
	int			sp_zr_len_dot;
	int			is_minus;
	long long	tmp;

	is_minus = 0;
	if (flag->character == 'u')
		tmp = va_arg(ap, unsigned int);
	else
		tmp = va_arg(ap, int);
	if ((is_minus = (tmp < 0 ? 1 : 0)) == 1)
		tmp *= -1;
	if (flag->character == 'u')
		ap_tmp = ft_litoa(tmp);
	else
		ap_tmp = ft_itoa(tmp);
	ap_tmp_len = ft_strlen(ap_tmp);
	sp_zr_len = flag->width - MAX(ap_tmp_len, flag->dot_width);
	if (flag->dot == 1 && flag->dot_width > ap_tmp_len)
		sp_zr_len_dot = flag->dot_width - ap_tmp_len;
	else
		sp_zr_len_dot = 0;
	if (flag->minus == 1 && sp_zr_len > 0 && is_minus == 1)
	{
		if (flag->dot == 1)
		{
			ft_putchar_fd('-', 1);
			print_sp_or_zr('0', sp_zr_len_dot);
			ft_putnstr(ap_tmp, ap_tmp_len);
		}
		else
		{
			ft_putchar_fd('-', 1);
			ft_putnstr(ap_tmp, ap_tmp_len);
			print_sp_or_zr(flag->zero_or_space, sp_zr_len - 1);
		}
	}
	else if (flag->minus == 1 && sp_zr_len > 0 && is_minus == 0)
	{
		if (flag->dot == 1)
		{
			print_sp_or_zr('0', sp_zr_len_dot);
			ft_putnstr(ap_tmp, ap_tmp_len);
		}
		else 
		{
			ft_putnstr(ap_tmp, ap_tmp_len);
			print_sp_or_zr(flag->zero_or_space, sp_zr_len);
		}
	}
	else if (flag->minus == 0 && sp_zr_len > 0 && is_minus == 1)
	{
		if (flag->dot == 1)
		{
			print_sp_or_zr(' ', sp_zr_len - 1);
			ft_putchar_fd('-', 1);
			print_sp_or_zr('0', sp_zr_len_dot);
			ft_putnstr(ap_tmp, ap_tmp_len);
		}
		else
		{
			ft_putchar_fd('-', 1);
			print_sp_or_zr(flag->zero_or_space, sp_zr_len - 1);
			ft_putnstr(ap_tmp, ap_tmp_len);
		}
	}
	else if (flag->minus == 0 && sp_zr_len > 0 && is_minus == 0)
	{
		if (flag->dot == 1)
		{
			print_sp_or_zr(' ', sp_zr_len);
			print_sp_or_zr('0', sp_zr_len_dot);
			ft_putnstr(ap_tmp, ap_tmp_len);
		}
		else
		{
			print_sp_or_zr(flag->zero_or_space, sp_zr_len);
			ft_putnstr(ap_tmp, ap_tmp_len);
		}
	}
	else
		ft_putnstr(ap_tmp, ap_tmp_len);
}
