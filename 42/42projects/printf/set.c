/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:10:16 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/31 21:08:09 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void set_dot_width(char **format, t_flag *flag)
{
	// int	tmp_dot_width;

	// tmp_dot_width = flag->dot_width;
	// printf("--------\n");
	while (ft_isdigit(**format))
	{
		flag->dot_width = (flag->dot_width * 10) + (**format - '0');
		(*format)++;
	}
	(*format)--;
}

void	set_width(char **format, t_flag *flag)
{
	int tmp_width;

	tmp_width = flag->width * 0;
	while (ft_isdigit(**format))
	{
		tmp_width = (tmp_width * 10) + (**format - '0');
		flag->width = tmp_width;
		(*format)++;
	}
}

void	set_dot(char **format, t_flag *flag)
{
	if (**format == '.')
	{
		flag->dot = 1;
		(*format)++;
	}
	if (ft_isdigit(**format) && flag->dot == 1)
		set_dot_width(format, flag);
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
