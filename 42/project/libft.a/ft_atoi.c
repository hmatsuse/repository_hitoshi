/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:22:24 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/29 16:59:07 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	count;
	long long int	num;

	count = 0;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += (long long int)*str - 48;
		str++;
	}
	if (count % 2 == 1)
		num *= -1;
	// if (num * -1 < -9223372036854775808 || num > 9223372036854775807)
	// 	return (-1);
	return ((int)num);
}
