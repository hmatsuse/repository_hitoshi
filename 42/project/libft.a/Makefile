NAME = libft.a
CC = gcc
PART1 =
PART2 =
BONUS =
ADDED =
SRCS = $(PART1) $(PART2) $(BONUS) $(ADDED)
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

PART1 += ft_isalnum.c
PART1 += ft_isalpha.c
PART1 += ft_isascii.c
PART1 += ft_isdigit.c
PART1 += ft_isprint.c
PART1 += ft_strlen.c
PART1 += ft_toupper.c
PART1 += ft_tolower.c
PART1 += ft_strdup.c
PART1 += ft_atoi.c




PART2 +=


BONUS +=


ADDED +=


$(NAME):
	$(CC) -c $(FLAGS) $(SRCS) -I libft.h
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re