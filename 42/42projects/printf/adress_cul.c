/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adress_cul.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 17:39:28 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/05 20:02:37 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_adress(char *str, t_flag *flag)
{
	int		sp_zr_len;
	int		sp_zr_len_dot;
	int		print_len;

	print_len = ft_strlen(str);
	if ((sp_zr_len = MAX(print_len, flag->dot_width) - flag->width) < 0)
		sp_zr_len = 0;
	if (flag->width == -1)
		sp_zr_len = 0;
	if ((sp_zr_len_dot = print_len - flag->dot_width) < 0)
		sp_zr_len_dot = 0;
	if (flag->minus == 1)
	{
		if (flag->dot == 1)
			print_sp_or_zr('0', sp_zr_len_dot, flag);
		ft_putnstr(str, print_len, flag);
		print_sp_or_zr(flag->zero_or_space, sp_zr_len, flag);
	}
	else if (flag->minus == 0)
	{
		print_sp_or_zr(flag->zero_or_space, sp_zr_len, flag);
		if (flag->dot == 1)
			print_sp_or_zr('0', sp_zr_len_dot, flag);
		ft_putnstr(str, print_len, flag);
	}
}

void	adress_cul(unsigned long tmp, char *src, t_flag *flag)
{
	char	*str;
	int		len;
	int		tmp1;

	len = 0;
	tmp1 = tmp;
	while (tmp /= 16)
		len++;
		printf("%d\n", len);
	if(!(str = (char *)malloc(sizeof(char) * (len))))
		return ;
	while (len >= 0)
	{
		str[len] = src[tmp1 % 16];
		tmp1 = tmp1 / 16;
		len--;
	}
	// str[len] = '\0';
	put_adress(str, flag);
}
