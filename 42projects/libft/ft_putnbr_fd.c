/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:09:58 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/30 14:00:35 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		num;

	if (n == -2147483648)
	{
		n = 147483648;
		ft_putnbr_fd(-2, fd);
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		num = n / 10;
		ft_putnbr_fd(num, fd);
		n %= 10;
	}
	if (n < 10)
	{
		n += '0';
		write(fd, &n, 1);
	}
}
