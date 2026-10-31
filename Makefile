CC	= clang # cc
CFLAGS	= -Wall -Wextra -Werror -I./

NAME	= libft.a

SRC_FOLDER_1	= srcs1
SRC_FOLDER_2	= srcs2
OBJ_FOLDER	= objs

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


SRCS2	= 	ft_substr.c	\
		ft_strjoin.c	\
		ft_strtrim.c

OBJS	= $(addprefix $(OBJ_FOLDER)/, $(SRCS1:.c=.o) $(SRCS2:.c=.o))

SRCS	=	$(addprefix $(SRC_FOLDER_1)/, $(SRCS1))	\
		$(addprefix $(SRC_FOLDER_2)/, $(SRCS2))
# 288abfd commit with everything correct.

all: $(NAME)

test:
	@echo NAME=$(NAME)
	@echo OBJS=$(OBJS)
	@echo SRCS=$(SRCS)

$(NAME): $(OBJS)
	@# r for insert/[r]eplace object files.
	@# c for [c]reating the file if it does not exist.
	@# s create the [s]ymbol index.
	ar rcs $(NAME) $(OBJS)


objs/%.o: srcs1/%.c 
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c $^ -o $@

objs/%.o: srcs2/%.c
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c $^ -o $@

norm:
	norminette $(SRCS) libft.h | grep -v ": OK!" ; exit "$${PIPESTATUS[0]}"
	@echo Norminette: all OK!

clean: 
	rm -rfv $(OBJ_FOLDER)

fclean: clean
	rm -fv $(NAME)

re: fclean all

eclean:
	rm -fv compile_commands.json
	rm -fv */compile_commands.json
	bear -- make
	cp -v compile_commands.json srcs1/
	cp -v compile_commands.json srcs2/
	$(MAKE) clean

unitests:
	$(MAKE) -C unitests/ VALG=0 QUIET=1

%:
	$(MAKE) -C unitests/ $@

.PHONY: unitests all clean fclean eclean norm
