/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:08:33 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/07/01 17:30:35 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		is_minus(int *n, size_t *minus)
{
	if (*n < 0)
	{
		*n *= -1;
		*minus = 1;
	}
}

char			*ft_itoa(int n)
{
	char	*tmp;
	int		num;
	size_t	minus;
	size_t	size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	size = 1;
	minus = 0;
	is_minus(&n, &minus);
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
