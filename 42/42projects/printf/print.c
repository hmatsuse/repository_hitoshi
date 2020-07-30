/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 19:42:32 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/30 21:05:18 by hmatsuse         ###   ########.fr       */
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

void	print_char(char **format, va_list ap, t_flag *flag)
{
	int		sp_zr_len;

	sp_zr_len = 0;
	if (flag->character == 'c')
	{
		// printf("%c\n", flag->character);
		// printf("----\n");
		if (flag->width == 0)
			return;
		else if (flag->width > 1)
		{
			sp_zr_len = flag->width - 1;
			if (flag->minus == 1)
			{
				ft_putchar_fd(va_arg(ap, int), 1);
				print_sp_or_zr(flag->zero_or_space, sp_zr_len);
			}
			if (flag->minus == 0)
			{
				print_sp_or_zr(flag->zero_or_space, sp_zr_len);
				ft_putchar_fd(va_arg(ap, int), 1);
			}
		}
		else
			ft_putchar_fd(va_arg(ap, int), 1);
	}
}
// void	print_num(char **format, va_list *ap, t_flag flag)
// {

// }
	// if (flag->character == 's')
	// if (flag->character == '%')