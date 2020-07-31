/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:42:32 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/31 18:47:00 by hmatsuse         ###   ########.fr       */
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
	int		sp_zr_len;
	char	*ap_tmp;

	ap_tmp = va_arg(ap, char *); 
	sp_zr_len = flag->width - (int)ft_strlen(ap_tmp);
	if (flag->minus == 1 && sp_zr_len > 0)
	{
		ft_putstr_fd(ap_tmp,1);
		print_sp_or_zr(flag->zero_or_space, sp_zr_len);
	}
	else if (flag->minus == 0 && sp_zr_len > 0)
	{
		print_sp_or_zr(flag->zero_or_space, sp_zr_len);
		ft_putstr_fd(ap_tmp, 1);
	}
	else
		ft_putstr_fd(ap_tmp, 1);
}
// void	print_num(char **format, va_list *ap, t_flag flag)
// {

// }
	// if (flag->character == '%')