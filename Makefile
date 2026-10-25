CC	= cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a
SRCS	= 	ft_isalpha.c \
		ft_isdigit.c

OBJS	= $(addprefix objs/, $(SRCS:.c=.o))


all: $(NAME)

test:
	@echo NAME=$(NAME)
	@echo OBJS=$(OBJS)
	@echo SRCS=$(SRCS)

$(NAME): $(OBJS)
	@# r for insert/replace object files.
	@# c for creating the file if it does not exist.
	@# s create the symbol index.
	ar rcs $(NAME) $(OBJS)

objs/%.o: %.c
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -fv $(OBJS)
fclean:
	rm -fv $(NAME)

re: clean fclean all
