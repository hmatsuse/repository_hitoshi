/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_concierge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:44:18 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/03 16:44:35 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_concierge(char **format, va_list ap, t_flag *flag)
{
	if (flag->character == 'c')
		print_c(format, ap ,flag);
	if (flag->character == 's')
		print_s(format, ap, flag);
	// if (flag->character == 'p')
	if (flag->character == 'd')
		print_d(format, ap, flag);
	if (flag->character == 'i')
		print_d(format, ap, flag);
	if (flag->character == 'u')
		print_d(format, ap, flag);
	// if (flag->character == 'x')
	// if (flag->character == 'X')
	if (flag->character == '%')
		ft_putchar_fd('%', 1);
}
