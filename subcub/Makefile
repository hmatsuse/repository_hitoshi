# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: knagashi <knagashi@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/13 13:46:51 by knagashi          #+#    #+#              #
#    Updated: 2020/12/13 13:46:52 by knagashi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d.a
HEADER	= includes
CC		= gcc
CFLAGS	= -O2 -Wall -Wextra -Werror
SRCS	= ${shell find ./srcs -type f -name "*.c"}
GNLSRCS = ${shell find ./get_next_Line -type f -name "*.c"}
OCHANGE = $(SRCS:.c=.o)
GNLOBJS = $(GNLSRCS:.c=.o)

$(NAME):		$(OCHANGE) $(GNLOBJS)
					ar rc $(NAME) $(OCHANGE) $(GNLOBJS)
					$(CC) $(CFLAGS) $(NAME) -I $(HEADER) libmlx.dylib -framework OpenGL -framework AppKit -o cub3D
.c.o:
					$(CC) $(CFLAGS) -I $(HEADER) -Imlx -c $< -o $@

all:			$(NAME)

clean:
					rm -f $(OCHANGE) $(GNLOBJS)

fclean:			clean
					rm -f $(NAME) cub3D

re:				fclean all

run:			re
					./cub3d
.PHONY:			clean fclean re all run
