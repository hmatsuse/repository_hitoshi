PROGRAM	= libft.a
CC		= gcc
SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
		  ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c\
		  ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
		  ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c\
		  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		  ft_toupper.c ft_tolower.c ft_min.c ft_calloc.c\
		  ft_strdup.c ft_strcpy.c ft_substr.c ft_strjoin.c\
		  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c\
		  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c\
		  ft_putnbr_fd.c free_malloc.c
BONUS	= ft_lstnew.c ft_lstadd_front.c\
		  ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
		  ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(BONUS:.c=.o)
CFLAGS	= -Wall -Wextra -Werror

$(PROGRAM): $(OBJS)
	ar rc $(PROGRAM) $(OBJS)

all: $(PROGRAM)

clean:
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

bonus: $(OBJS_B) $(PROGRAM)
	ar rc $(PROGRAM) $(OBJS_B)

.PHONY: all clean fclean re
