#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/05 11:20:42 by marisous          #+#    #+#              #
#    Updated: 2026/11/10 15:41:16 by marisous         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC	= cc
CFLAGS	= -Wall -Wextra -Werror $(addprefix -I, $(INC_FOLDERS))

NAME	= libft.a

OBJ_FOLDER	= objs
SRC_FOLDER	= .
INC_FOLDERS	= .

PART_1	= 	isalpha isdigit isalnum isascii isprint strlen \
		memset bzero memcpy memmove strlcpy strlcat toupper \
		tolower strchr strrchr strncmp memchr memcmp \
		strnstr atoi calloc strdup

PART_2	= 	strjoin strtrim substr split itoa strmapi striteri \
		putchar_fd putstr_fd putendl_fd putnbr_fd 

PART_3	= 	lstnew lstadd_front lstsize lstlast lstadd_back \
		lstdelone lstclear lstiter lstmap		

SRCS	=	$(addsuffix .c, \
			$(addprefix ft_, $(PART_1) $(PART_2) $(PART_3)))

OBJS	= 	$(addprefix $(OBJ_FOLDER)/, 	$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@# r for insert/[r]eplace object files.
	@# c for [c]reating the file if it does not exist.
	@# s create the [s]ymbol index.
	ar rcs $(NAME) $(OBJS)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	@mkdir -p objs/
	$(CC) $(CFLAGS) -c $^ -o $@

clean: 
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test test_% norm unitests eclean

test:
	@echo NAME=$(NAME)
	@echo OBJS=$(OBJS)
	@echo SRCS=$(SRCS)

norm:
	norminette $(SRCS) libft.h | grep -v ": OK!" # ; status=$${PIPESTATUS[0]} ; exit $$status	
	@echo Norminette: all OK!
	@echo "Number of functions: mine: 43 | theirs: $$(ls -1 ft*.c | wc -l)"
	@echo "Static functions: mine: 7 | theirs: $$(grep -l '\bstatic\b' *.c | wc -l)"
	@echo "Includes: $$(grep include $(SRCS) | grep -v libft.h)"
	@for f in *.c; do \
		count=$$(ctags -x --c-kinds=f "$$f" | wc -l); \
		if [ "$$count" -gt 1 ]; then \
			printf "%-20s %s\n" "$$f" "$$count"; \
		fi; \
	done

eclean:
	rm -fv compile_commands.json
	bear -- make
	$(MAKE) fclean

unitests:
	$(MAKE) -C unitests/ VALG=0 QUIET=1

test_%: 
	$(MAKE) -C unitests/ $*


# # As a 3 part project, the files were originally distributed 
# SRC_FOLDER_1	= ./
# SRC_FOLDER_2	= ./
# SRC_FOLDER_3	= ./
# SRCS1	=	$(addsuffix .c, $(addprefix ft_, $(PART_1)))
# SRCS2	=	$(addsuffix .c, $(addprefix ft_, $(PART_2)))
# SRCS3	=	$(addsuffix .c, $(addprefix ft_, $(PART_3)))
# SRCS	=	$(addprefix $(SRC_FOLDER_1)/, $(SRCS1))	\
# 		$(addprefix $(SRC_FOLDER_2)/, $(SRCS2)) \
# 		$(addprefix $(SRC_FOLDER_3)/, $(SRCS3))
# OBJS	= 	$(addprefix $(OBJ_FOLDER)/ft_, 	$(SRCS1:.c=.o) \
# 						$(SRCS2:.c=.o) \
# 						$(SRCS3:.c=.o))
# objs/%.o: $(SRC_FOLDER_1)/%.c 
# 	@mkdir -p objs/
# 	$(CC) $(CFLAGS) -c $^ -o $@
# objs/%.o: $(SRC_FOLDER_2)/%.c
# 	@mkdir -p objs/
# 	$(CC) $(CFLAGS) -c $^ -o $@
# objs/%.o: $(SRC_FOLDER_3)/%.c
# 	@mkdir -p objs/
# 	$(CC) $(CFLAGS) -c $^ -o $@
# Use flag to compile for francinette at home
# CFLAGS	+= -gdwarf-4
# eclean:
# 	rm -fv compile_commands.json
# 	rm -fv */compile_commands.json
# 	bear -- make
# 	cp -v compile_commands.json $(SRC_FOLDER_1)/
# 	cp -v compile_commands.json $(SRC_FOLDER_2)/
# 	cp -v compile_commands.json $(SRC_FOLDER_3)/
# 	$(MAKE) fclean
