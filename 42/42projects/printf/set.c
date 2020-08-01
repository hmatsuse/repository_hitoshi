/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:10:16 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/01 17:31:01 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void set_dot_width(char **format, t_flag *flag)
{
	int	tmp_dot_width;

	tmp_dot_width = 0;
	while (ft_isdigit(**format))
	{
		tmp_dot_width = (tmp_dot_width * 10) + (**format - '0');
		flag->dot_width = tmp_dot_width;
		(*format)++;
	}
}

void	set_width(char **format, va_list ap, t_flag *flag)
{
	int tmp_width;

	tmp_width = flag->width * 0;
	while (ft_isdigit(**format))
	{
		tmp_width = (tmp_width * 10) + (**format - '0');
		flag->width = tmp_width;
		(*format)++;
	}
	if (**format == '*')
	{
		flag->width = va_arg(ap, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus = 1;
			flag->zero_or_space = ' ';
		}
		(*format)++;
	}
}

void	set_dot(char **format, va_list ap, t_flag *flag)
{
	while (**format == '.' || ft_isdigit(**format))
	{
		if (**format =='.')
		{
			flag->dot = 1;
			(*format)++;
		}
		if (ft_isdigit(**format) && flag->dot == 1)
			set_dot_width(format, flag);
	}
	if (**format == '*')
	{
		flag->dot_width = va_arg(ap, int);
		if (flag->dot_width < 0)
			flag->dot = 0;
		(*format)++;
	}
}

void	set_flag(char **format, t_flag *flag)
{
	while (**format == '-' || **format == '0' || **format == '+')
	{
		if (**format == '-')
		{
			if (flag->zero_or_space == '0')
				flag->zero_or_space = ' ';
			flag->minus = 1;
		}
		if (**format == '0' && flag->minus != 1)
			flag->zero_or_space = '0';
		if (**format == '+')
			flag->plus = 1;
		(*format)++;
	}
}

void	set_char(char **format, t_flag *flag)
{
	if (**format == 'c')
		flag->character = 'c';
	if (**format == 's')
		flag->character = 's';
	if (**format == 'd')
		flag->character = 'd';
	if (**format == 'p')
		flag->character = 'p';
	if (**format == 'x')
		flag->character = 'x';
	if (**format == 'X')
		flag->character = 'X';
	if (**format == '%')
		flag->character = '%';
}
