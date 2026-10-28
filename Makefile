CC	= clang # cc
CFLAGS	= -Wall -Wextra -Werror

NAME	= libft.a
SRCS	= 	ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_strlen.c	\
		ft_memset.c	\
		ft_bzero.c	\
		ft_memcpy.c	\
		ft_memmove.c	\
		ft_strlcpy.c	\
		ft_strlcat.c	\
		ft_toupper.c	\
		ft_tolower.c

OBJS	= $(addprefix objs/, $(SRCS:.c=.o))


all: $(NAME)

%: all

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

norm:
	norminette $(SRCS) libft.h

clean:
	rm -fv $(OBJS)
fclean:
	rm -fv $(NAME)

re: clean fclean all
