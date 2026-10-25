CC	= cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a
SRCS	= ft_isalpha.c


OBJS	= $(SRCS:.o=.c)

all: $(NAME)

$(NAME): $(OBJS)
	# r for insert/replace object files.
	# c for creating the file if it does not exist.
	# s create the symbol index.
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -fv $(OBJS)
fclean:
	rm -fv $(NAME)

re: clean fclean all
