/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:35:25 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/01 19:29:39 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

typedef struct	s_flag
{
	int		zero_or_space;
	int		minus;
	int		plus;
	// int		bash;
	// int		space;
	int		width;
	int		dot;
	int		dot_width;
	char	character;
	char	*str;
	// int		printlen;
	// int		slen;
}				t_flag;

int		check_char(char **format, va_list ap, t_flag *flag);

// SET FUNCTIONS
void	set_flag(char **format, t_flag *flag);
void	set_width(char **format, va_list ap, t_flag *flag);
void	set_dot(char **format, va_list ap, t_flag *flag);
void	set_char(char **format, t_flag *flag);

// PRINT FUNCTIONS
void	print_concierge(char **format, va_list ap, t_flag *flag);
void	print_c(char **format, va_list ap, t_flag *flag);
void	print_s(char **format, va_list ap, t_flag *flag);
void	print_d(char **format, va_list ap, t_flag *flag);

// UTILS FUNCTIONS
void	ft_putnstr(char *ap_tmp, int len);
int		ft_min(int	ap_tmp, int dot_width);

#endif
