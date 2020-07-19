/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukada <nfukada@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 00:39:58 by nfukada           #+#    #+#             */
/*   Updated: 2020/07/04 11:39:28 by nfukada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define STATUS_LINE	1
# define STATUS_ERROR	-1

int		get_next_line(int fd, char **line);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strncpy(char *dest, const char *src, size_t n);
int		append_line(char **line, const char *src);

#endif
