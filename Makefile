CC	= clang # cc
CFLAGS	= -Wall -Wextra -Werror -I./

NAME	= libft.a

SRCS1	= 	ft_isalpha.c	\
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
		ft_tolower.c	\
		ft_strchr.c	\
		ft_strrchr.c	\
		ft_strncmp.c	\
		ft_memchr.c	\
		ft_memcmp.c	\
		ft_strnstr.c	\
		ft_atoi.c	\
		ft_calloc.c	\
		ft_strdup.c
OBJS_1	= $(addprefix objs1/, $(SRCS1:.c=.o))
SRCS_1	= $(addprefix srcs1/, $(SRCS1))
# 288abfd commit with everything correct.


SRCS2	= 	ft_substr.c

OBJS_2	= $(addprefix objs2/, $(SRCS2:.c=.o))
SRCS_2	= $(addprefix srcs2/, $(SRCS2))
# 288abfd commit with everything correct.

OBJS	= $(OBJS_1) $(OBJS_2) $(OBJS_3)

all: $(NAME)

test:
	@echo NAME=$(NAME)
	@echo OBJS_1=$(OBJS_1)
	@echo SRCS_1=$(SRCS_1)

$(NAME): $(OBJS)
	@# r for insert/[r]eplace object files.
	@# c for [c]reating the file if it does not exist.
	@# s create the [s]ymbol index.
	ar rcs $(NAME) $(OBJS)

objs1/%.o: srcs1/%.c
	@mkdir -p objs1/
	$(CC) $(CFLAGS) -c $^ -o $@

objs2/%.o: srcs2/%.c
	@mkdir -p objs2/
	$(CC) $(CFLAGS) -c $^ -o $@

norm:
	norminette $(SRCS) libft.h | grep -v ": OK!" ; exit "$${PIPESTATUS[0]}"
	@echo Norminette: all OK!

clean:
	rm -fv $(OBJS)
fclean:
	rm -fv $(NAME)

re: clean fclean all
