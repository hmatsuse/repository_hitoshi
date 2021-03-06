/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_cul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:39:28 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/09 18:01:52 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_set(char *str, t_flag *flag)
{
	flag->print_len = ft_strlen(str);
	if (flag->character == 'p')
		flag->width -= 2;
	if ((flag->sp_zr_len = flag->width - MAX(flag->print_len,\
	flag->dot_width)) < 0)
		flag->sp_zr_len = 0;
	if (flag->width == -1)
		flag->sp_zr_len = 0;
	if ((flag->sp_zr_len_dot = flag->dot_width - flag->print_len) < 0)
		flag->sp_zr_len_dot = 0;
}

void	put_adress(char *str, t_flag *flag)
{
	len_set(str, flag);
	if (flag->minus == 1)
	{
		if (flag->character == 'p')
			ft_putnstr("0x", 2, flag);
		if (flag->dot == 1)
			print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
		ft_putnstr(str, flag->print_len, flag);
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
	}
	else if (flag->minus == 0)
	{
		print_sp_or_zr(flag->zero_or_space, flag->sp_zr_len, flag);
		if (flag->character == 'p')
			ft_putnstr("0x", 2, flag);
		if (flag->dot == 1)
			print_sp_or_zr('0', flag->sp_zr_len_dot, flag);
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
	if (!(str = (char *)malloc(sizeof(char) * (len + 2))))
		return ;
	str[len + 1] = '\0';
	while (len >= 0)
	{
		str[len] = src[tmp1 % 16];
		tmp1 = tmp1 / 16;
		len--;
	}
	if (flag->dot == 1 && str[0] == '0')
	{
		free(str);
		str = ft_strdup("");
	}
	put_adress(str, flag);
	free(str);
}
