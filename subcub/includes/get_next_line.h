/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 15:52:37 by hmatsuse          #+#    #+#             */
/*   Updated: 2020/12/20 14:30:59 by hmatsuse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

int			get_next_line(int fd, char **line);
int			ft_strlen(char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
int			ck_nl(char *str);
int			count_until_nl(char *concatline);

#endif
