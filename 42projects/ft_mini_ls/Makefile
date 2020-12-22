NAME = ft_mini_ls
CC = gcc
RM = rm -f
SRCS = ft_mini_ls.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
LIBS = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
