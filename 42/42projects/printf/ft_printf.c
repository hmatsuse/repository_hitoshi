/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:52:13 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/03 22:29:09 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		reset_flag(t_flag *flag)
{
	flag->zero_or_space = ' ';
	flag->minus = 0;
	flag->plus = 0;
	flag->width = -1;
	flag->character = 0;
	flag->dot = 0;
	flag->dot_width = 0;
	return (0);
}

int		check_char(char **format, va_list ap, t_flag *flag)
{
	reset_flag(flag);
	set_flag(format, flag);
	set_width(format, ap, flag);
	set_dot(format, ap, flag);
	set_char(format, flag);
	print_concierge(ap, flag);
	(*format)++;
	return (0);
}

int		check(char *format, va_list ap, t_flag *flag)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			check_char(&format, ap, flag);
			reset_flag(flag);
		}
		else
		{
			ft_putchar_fd_len(*format, 1, flag);
			format++;
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_flag	*flag;
	int		printlen;

	if (!(flag = malloc(sizeof(t_flag))))
		return (-1);
	ft_bzero(flag, sizeof(t_flag));
	va_start(ap, format);
	check((char *)format, ap, flag);
	va_end(ap);
	printlen = flag->printlen;
	free(flag);
	flag = NULL;
	return (printlen);
}
