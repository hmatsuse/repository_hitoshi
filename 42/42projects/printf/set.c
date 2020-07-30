/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:10:16 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/30 21:06:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_flag(char **format, t_flag *flag)
{
	if (**format == '-')
	{
		flag->minus = 1;
		(*format)++;
	}
	if (**format == '0')
	{
		flag->zero_or_space = '0';
		(*format)++;
	}
	if (**format == '+')
	{
		flag->plus = 1;
		(*format)++;
	}
	if (**format == '.')
	{
		flag->dot = 1;
		(*format)++;
	}
}

void	set_width(char **format, t_flag *flag)
{
	int tmp_width;

	tmp_width = flag->width * 0;
	while (ft_isdigit(**format))
	{
		flag->width = tmp_width * 10 + (**format - '0');
		(*format)++;
	}
	// printf("%d\n", flag->width);
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
