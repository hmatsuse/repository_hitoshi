# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmatsuse <hmatsuse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/29 16:28:46 by hmatsuse          #+#    #+#              #
#    Updated: 2020/12/20 05:02:19 by hmatsuse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d.a
HEADER	= includes
CC		= gcc
RM		= rm -f
CFLAGS	= -O2 -Wall -Wextra -Werror
SRCS	= ${shell find ./srcs -type f -name "*.c"}
GNLSRCS = ${shell find ./get_next_Line -type f -name "*.c"}
OCHANGE = $(SRCS:.c=.o)
GNLOBJS = $(GNLSRCS:.c=.o)

$(NAME): $(OCHANGE) $(GNLOBJS)
	ar rc $(NAME) $(OCHANGE) $(GNLOBJS)
	$(CC) $(CFLAGS) $(NAME) -I $(HEADER) libmlx.dylib -framework OpenGL -framework AppKit -o cub3D

.c.o:
	$(CC) $(CFLAGS) -I $(HEADER) -Imlx -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OCHANGE) $(GNLOBJS)

fclean: clean
	$(RM) $(NAME) cub3D

re: fclean all

run: re
	./cub3d
	
.PHONY: clean fclean re all run
