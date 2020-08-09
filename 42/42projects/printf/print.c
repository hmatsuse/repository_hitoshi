/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:42:32 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/09 19:02:27 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sp_or_zr(char sp_or_zr, int sp_zr_len, t_flag *flag)
{
	int i;

	i = 0;
	if (sp_zr_len < 0)
		return ;
	while (i++ != sp_zr_len)
		ft_putchar_fd_len(sp_or_zr, 1, flag);
}

void	print_c(va_list ap, t_flag *flag)
{
	flag->sp_zr_len = flag->width - 1;
	if (flag->minus == 1 && flag->sp_zr_len > 0)
	{
		ft_putchar_fd_len(va_arg(ap, int), 1, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
	else if (flag->minus == 0 && flag->sp_zr_len > 0)
	{
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		ft_putchar_fd_len(va_arg(ap, int), 1, flag);
	}
	else
		ft_putchar_fd_len(va_arg(ap, int), 1, flag);
}

void	print_s(va_list ap, t_flag *flag)
{
	char	*ap_tmp;

	ap_tmp = va_arg(ap, char *);
	if (ap_tmp == NULL)
		ap_tmp = "(null)";
	if (flag->dot == 1)
		flag->print_len = ft_min((int)ft_strlen(ap_tmp), flag->dot_width);
	else
		flag->print_len = (int)ft_strlen(ap_tmp);
	flag->sp_zr_len = flag->width - flag->print_len;
	if (flag->minus == 1 && flag->sp_zr_len > 0)
	{
		ft_putnstr(ap_tmp, flag->print_len, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
	else if (flag->minus == 0 && flag->sp_zr_len > 0)
	{
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		ft_putnstr(ap_tmp, flag->print_len, flag);
	}
	else
		ft_putnstr(ap_tmp, flag->print_len, flag);
}

void	print_d(va_list ap, t_flag *flag)
{
	char		*ap_tmp;

	if (flag->character == 'u')
		flag->tmp = va_arg(ap, unsigned int);
	else
		flag->tmp = va_arg(ap, int);
	if ((flag->diu_is_minus = (flag->tmp < 0 ? 1 : 0)) == 1)
		flag->tmp *= -1;
	ap_tmp = ft_litoa(flag->tmp);
	flag->print_len = ft_strlen(ap_tmp);
	flag->sp_zr_len = flag->width - MAX(flag->print_len, flag->dot_width);
	if (flag->dot == 1 && flag->dot_width > flag->print_len)
		flag->sp_zr_len_dot = flag->dot_width - flag->print_len;
	else
		flag->sp_zr_len_dot = 0;
	if (flag->diu_is_minus == 1 && flag->sp_zr_len > 0)
		flag->sp_zr_len -= 1;
	if (flag->dot == 1)
		flag->zero_or_space = ' ';
	diu(ap_tmp, flag);
	free(ap_tmp);
}

void	print_adress(va_list ap, t_flag *flag)
{
	unsigned long	tmp;

	tmp = 0;
	if (flag->dot == 1)
		flag->zero_or_space = ' ';
	if (flag->character == 'p' || flag->character == 'x')
	{
		if (flag->character == 'p')
			tmp = va_arg(ap, unsigned long);
		else if (flag->character == 'x')
			tmp = va_arg(ap, unsigned int);
		adress_cul(tmp, "0123456789abcdef", flag);
	}
	else if (flag->character == 'X')
	{
		tmp = va_arg(ap, unsigned int);
		adress_cul(tmp, "0123456789ABCDEF", flag);
	}
}
