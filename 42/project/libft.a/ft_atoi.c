/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:22:24 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/06/26 12:12:15 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	count;
	long long	num;

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
		num += *str - 48;
		str++;
	}
	if (count % 2 == 1)
		num *= -1;
	return ((int)num);
}

// int		main(void)
// {
// 	char	str[] = "123456789";
// 	int		num;

// 	num = ft_atoi(str);
// 	printf("%d\n", num);
// 	printf("%s => %d\n", "-123", ft_atoi("-123"));
// 	printf("%s => %d\n", "3.14", ft_atoi("3.14"));
// 	printf("%s => %d\n", "XYZ",	ft_atoi("XYZ"));
// 	printf("%s => %d\n", "5G", ft_atoi("5G"));
// 	printf("%s => %d\n", "G5", ft_atoi("G5"));
// 	printf("%s => %d\n", "1 2 3", ft_atoi("1 2 3"));
// 	printf("%s => %d\n", "    1", ft_atoi("    1"));
// 	printf("%s => %d\n", "1,2,3", ft_atoi("1,2,3"));
// 	return (0);
// }
