/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_cul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:39:28 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/08 12:47:16 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_adress(char *str, t_flag *flag)
{
	flag->print_len = ft_strlen(str);
	if ((flag->sp_zr_len = flag->width - MAX(flag->print_len, flag->dot_width)) < 0)
		flag->sp_zr_len = 0;
	if (flag->width == -1)
		flag->sp_zr_len = 0;
	if ((flag->sp_zr_len_dot = flag->dot_width - flag->print_len) < 0)
		flag->sp_zr_len_dot = 0;
	if (flag->minus == 1)
	{
		if (flag->dot == 1)
			print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr(str, flag->print_len, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
	else if (flag->minus == 0)
	{
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		if (flag->dot == 1)
			print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr(str, flag->print_len, flag);
	}
}

void	put_adress_p(char *str, t_flag *flag)
{
	flag->print_len = ft_strlen(str) + 2;
	if ((flag->sp_zr_len = flag->width - MAX(flag->print_len,\
	flag->dot_width)) < 0)
		flag->sp_zr_len = 0;
	if (flag->width == -1)
		flag->sp_zr_len = 0;
	if ((flag->sp_zr_len_dot = flag->dot_width - flag->print_len) < 0)
		flag->sp_zr_len_dot = 0;
	if (flag->minus == 1)
	{
		if (flag->dot == 1)
			print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr("0x", 2, flag);
		ft_putnstr(str, flag->print_len, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
	else if (flag->minus == 0)
	{
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		if (flag->dot == 1)
			print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr("0x", 2, flag);
		ft_putnstr(str, flag->print_len, flag);
	}
}

void	adress_cul(unsigned long tmp, char *src, t_flag *flag)
{
	char			*str;
	int				len;
	unsigned long	tmp1;

	len = 0;
	tmp1 = tmp;
	while (tmp /= 16)
		len++;
	if(!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return ;
	str[len + 1] = '\0';
	while (len >= 0)
	{
		str[len] = src[tmp1 % 16];
		tmp1 = tmp1 / 16;
		len--;
	}
	if (flag->dot == 1 && str[0] == '0')
		str = "";
	if (flag->character == 'p')
		put_adress_p(str, flag);
	else
		put_adress(str, flag);
	// free(str);
}
