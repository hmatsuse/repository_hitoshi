NAME = printf.a
CC = gcc
RM = rm -f
SRCS = ft_printf.c print.c print_concierge.c set.c utils.c
OBJS = $(SRCS:.c=.o)
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
