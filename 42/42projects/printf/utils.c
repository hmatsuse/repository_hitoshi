/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:06:54 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/03 16:41:22 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char *ap_tmp, int len)
{
	int	i;

	i = 0;
	while (ap_tmp[i] != '\0' && i < len)
	{
		write(1, &ap_tmp[i], 1);
		i++;
	}	
}

int		ft_min(int	ap_tmp, int dot_width)
{
	if (ap_tmp > dot_width)
		return (dot_width);
	return (ap_tmp);
}


static void		is_lminus(long long *n, size_t *minus)
{
	if (*n < 0)
	{
		*n *= -1;
		*minus = 1;
	}
}

char			*ft_litoa(long long n)
{
	char		*tmp;
	long long	num;
	size_t		minus;
	size_t		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	size = 1;
	minus = 0;
	is_lminus(&n, &minus);
	while (num /= 10)
		size++;
	size += minus;
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tmp[size] = '\0';
	while (size--)
	{
		tmp[size] = n % 10 + '0';
		n /= 10;
	}
	if (minus)
		tmp[0] = '-';
	return (tmp);
}
