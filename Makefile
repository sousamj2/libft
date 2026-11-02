CC	= clang # cc
CFLAGS	= -Wall -Wextra -Werror -I./

NAME	= libft.a

SRC_FOLDER_1	= srcs1
SRC_FOLDER_2	= srcs2
SRC_FOLDER_3	= srcs3
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
		ft_strtrim.c	\
		ft_split.c	\
		ft_itoa.c	\
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putnbr_fd.c	\
		ft_putendl_fd.c

SRCS3	= 	ft_lstnew.c		\
		ft_lstadd_front.c 	\
		ft_lstsize.c		\
		ft_lstlast.c		\
		ft_lstadd_back.c	\
		ft_lstdelone.c		\
		ft_lstclear.c		\
		ft_lstiter.c		\
		ft_lstmap.c		


OBJS	= $(addprefix $(OBJ_FOLDER)/, $(SRCS1:.c=.o) $(SRCS2:.c=.o) $(SRCS3:.c=.o))

SRCS	=	$(addprefix $(SRC_FOLDER_1)/, $(SRCS1))	\
		$(addprefix $(SRC_FOLDER_2)/, $(SRCS2)) \
		$(addprefix $(SRC_FOLDER_3)/, $(SRCS3))
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

objs/%.o: srcs3/%.c
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c $^ -o $@
norm:
	norminette $(SRCS) libft.h | grep -v ": OK!" ; exit "$${PIPESTATUS[0]}"
	@echo Norminette: all OK!

clean: 
	rm -rfv $(OBJ_FOLDER)

fclean: 
	rm -fv $(NAME)

re: fclean all

eclean:
	rm -fv compile_commands.json
	rm -fv */compile_commands.json
	bear -- make
	cp -v compile_commands.json srcs1/
	cp -v compile_commands.json srcs2/
	cp -v compile_commands.json srcs3/
	$(MAKE) clean

unitests:
	$(MAKE) -C unitests/ VALG=0 QUIET=1

uaa%: all
	$(MAKE) -C unitests/ $@

.PHONY: unitests all clean fclean eclean norm re
