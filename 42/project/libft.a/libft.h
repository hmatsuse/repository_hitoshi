#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
int	ft_min(int s1, int s2);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int n);
int	ft_isdigit(int c);
int	ft_isdigit(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int	ft_atoi(const char *str);
char *strdup(const char *s1);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);



#endif