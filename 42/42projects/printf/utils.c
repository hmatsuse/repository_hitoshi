/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 14:06:54 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/01 14:17:52 by hmatsuse         ###   ########.fr       */
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
