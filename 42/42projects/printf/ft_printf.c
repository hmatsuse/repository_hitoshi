/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:52:13 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/27 20:22:56 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		c(char **format, va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1);
	return (0);
}

int		set_flag(char **format, t_flag *flag)
{
	if (**format == '-')
		flag->minus = '-';
	if (**format == '0')
		flag->zero_or_space = '0';
	if (**format == '+')
		flag->plus = '+';
	if (**format == '.')
		flag->dot = '.';
	return (0);
}

int		reset_flag(t_flag *flag)
{
	flag->zero_or_space = ' ';
	flag->minus = 0;
	flag->plus = 0;
	flag->width = 0;
	flag->character = 0;
	return (0);
}

int		check_char(char **format, va_list ap, t_flag *flag)
{
	reset_flag(flag);
	if (**format == '-' || **format == '+' || \
	**format == '0' || **format == '.')
		set_flag(ap, &flag);
	if (**format == 'c')
		c(format, ap);
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
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_flag	*flag;
	int		print_len;

	if (!(flag = malloc(sizeof(t_flag))))
		return (-1);
	ft_bzero(flag, sizeof(t_flag));
	va_start(ap, format);
	print_len = check((char *)format, ap, flag);
	va_end(ap);
	free(flag);
	flag = NULL;
	return (print_len);
}

int		main(void)
{
	ft_printf("ab%cde%cf\n", '+', '-');
	printf("ab%cde%cf\n", '+', '-');
	return (0);
}
