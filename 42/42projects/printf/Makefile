NAME = libftprintf.a
CC = gcc
RM = rm -f
SRCS = ft_printf.c print.c print_concierge.c set.c utils.c adress_cul.c
OBJS = $(SRCS:.c=.o)
# CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
