/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_concierge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 17:44:18 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/06 17:44:50 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_concierge(va_list ap, t_flag *flag)
{
	if (flag->character == 'c')
		print_c(ap ,flag);
	if (flag->character == 's')
		print_s(ap, flag);
	if (flag->character == 'p')
		print_adress(ap, flag);
	if (flag->character == 'd')
		print_d(ap, flag);
	if (flag->character == 'i')
		print_d(ap, flag);
	if (flag->character == 'u')
		print_d(ap, flag);
	if (flag->character == 'x')
		print_adress(ap, flag);
	if (flag->character == 'X')
		print_adress(ap, flag);
	if (flag->character == '%')
		print_percent(flag);
}
