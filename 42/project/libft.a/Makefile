PROGRAM = libft.a
CC = gcc
SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_min.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

$(PROGRAM):
	$(CC) -c $(FLAGS) $(SRCS) -I libft.h
	ar rcs $(PROGRAM) $(OBJS)

all: $(PROGRAM)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: all clean fclean re