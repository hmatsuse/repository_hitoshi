/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 16:35:25 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/08/06 16:50:04 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

# define MAX(x, y) (x > y ? x : y)
typedef struct	s_flag
{
	int		zero_or_space;
	int		minus;
	int		plus;
	int		width;
	int		dot;
	int		dot_width;
	char	character;
	int		printlen;
}				t_flag;

int		check_char(char **format, va_list ap, t_flag *flag);

// SET FUNCTIONS
void	set_flag(char **format, t_flag *flag);
void	set_width(char **format, va_list ap, t_flag *flag);
void	set_dot(char **format, va_list ap, t_flag *flag);
void	set_char(char **format, t_flag *flag);

// PRINT FUNCTIONS
void	print_concierge(va_list ap, t_flag *flag);
void	print_c(va_list ap, t_flag *flag);
void	print_s(va_list ap, t_flag *flag);
void	print_d(va_list ap, t_flag *flag);
void	print_adress(va_list ap, t_flag *flag);
void	print_sp_or_zr(char	sp_or_zr, int sp_zr_len, t_flag *flag);

void	adress_cul(unsigned long tmp, char *src, t_flag *flag);

// UTILS FUNCTIONS
void	ft_putnstr(char *ap_tmp, int len ,t_flag *flag);
void	ft_putchar_fd_len(char c, int fd, t_flag *flag);
int		ft_min(int	ap_tmp, int dot_width);
char	*ft_litoa(long long n);
void	is_lminus(long long *n, size_t *minus);

#endif
