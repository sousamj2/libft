VALG	= 1
ASAN	= 0
DEBUG	= -g -O0
QUIET	= 0
RMRUN	= 1
NMEM	= 0

EVALUSER = gluciano

PROJECTS = /home/marisous/Projects42/libft/
TESTDIR = /home/marisous/evals/libft/$(EVALUSER)/
# TESTDIR = ..

Q = $(if $(filter 1,$(QUIET)),@,)

CC	= cc -std=c99 -D_DEFAULT_SOURCE
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I$(TESTDIR)
CFLAGS	+= -L$(TESTDIR)
LIBS	+= -lft -lc -lbsd
PREXEC	= ulimit -v 131072; timeout 5s
MALLOC	= -Wl,--wrap=malloc,--wrap=free

ifeq ($(VALG),1)
	EXEC	= valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 --track-origins=yes -s
	PREXEC	= ulimit -v 262144; timeout 5s
else
	ifeq ($(ASAN),1)
		COMP	= -fsanitize=address,leak
		PREXEC	= timeout 5s env ASAN_OPTIONS=halt_on_error=1
	endif
endif

RAND_UNITS_01	= 	strlen memset bzero memcpy memmove \
			strlcpy strlcat strchr strrchr \
			strncmp memchr memcmp strnstr atoi \
			calloc strdup

MEMO_UNITS_01	= 	memset bzero memcpy memmove \
			strlcpy strlcat strchr strrchr \
			memchr memcmp

UNITS_01	= 	isalpha isdigit isalnum isascii isprint \
			strlen memset bzero memmove \
			strlcpy strlcat toupper tolower \
			strchr strrchr strncmp\
			memchr memcmp strnstr atoi \
			calloc strdup

RAND_UNITS_02	= 	putchar_fd putstr_fd putendl_fd putnbr_fd

MEMO_UNITS_02	= 	

UNITS_02	= 	test_strjoin test_strtrim test_substr test_split \
			test_itoa test_strmapi test_striteri test_putchar_fd \
			test_putstr_fd test_putendl_fd test_putnbr_fd \
			strjoin strtrim substr split \
			itoa strmapi striteri putchar_fd \
			putstr_fd putendl_fd putnbr_fd 

RAND_UNITS_03	= 	arraylist  charlist  intlist  strlist

MEMO_UNITS_03	=

LIST_UNITS_03	= 	arraylist  charlist  intlist  strlist

UNITS_03	= 	charlist # intlist  strlist arraylist  

MALLOC_UNITS_02	=	split itoa strjoin substr
MALLOC_UNITS_03	=	charlist

all: libft $(UNITS_01) $(UNITS_02) $(UNITS_03)

libft:
	$(MAKE) -C ..

test:
	@echo --------------------
	@echo Configuration
	@echo --------------------
	@echo VALG: $(VALG)
	@echo ASAN: $(ASAN)
	@echo EXEC: $(EXEC)
	@echo COMP: $(COMP)
	@echo QUIET: $(QUIET)
	@echo DEBUG: $(DEBUG)
	@echo --------------------
	@echo List of jobs
	@echo --------------------
	@echo UNITS_01: $(UNITS_01)
	@echo UNITS_02: $(UNITS_02)
	@echo UNITS_03: $(UNITS_03)
	@echo --------------------
	@echo Using random.c
	@echo --------------------
	@echo RAND_UNITS_01: $(RAND_UNITS_01)
	@echo RAND_UNITS_02: $(RAND_UNITS_02)
	@echo RAND_UNITS_03: $(RAND_UNITS_03)
	@echo --------------------

norm $(addprefix build1_, $(RAND_UNITS_01)) \
norm $(addprefix build2_, $(RAND_UNITS_02)) \
norm $(addprefix build3_, $(RAND_UNITS_03)) : AUX += ft_random.c

norm $(addprefix build1_, $(MEMO_UNITS_01)) \
norm $(addprefix build2_, $(MEMO_UNITS_02)) \
norm $(addprefix build3_, $(MEMO_UNITS_03)) : AUX += ft_memory.c

norm $(addprefix build3_, $(LIST_UNITS_03)) : AUX += ft_lists.c

$(addprefix build1_, $(MALLOC_UNITS_01)) \
$(addprefix build2_, $(MALLOC_UNITS_02)) \
$(addprefix build3_, $(MALLOC_UNITS_03)) : LFLAGS += $(MALLOC)

$(addprefix build1_, $(MALLOC_UNITS_01)) \
$(addprefix build2_, $(MALLOC_UNITS_02)) \
$(addprefix build3_, $(MALLOC_UNITS_03)) : AUX += ft_malloc.c

$(addprefix build1_, $(MALLOC_UNITS_01)) \
$(addprefix build2_, $(MALLOC_UNITS_02)) \
$(addprefix build3_, $(MALLOC_UNITS_03)) : CFLAGS +=  -DCHECK_MEM_NUM=$(NMEM)


build1_%: srcs1/ft_%.c $(AUX)
	$(Q)$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LFLAGS) $(LIBS)

build2_%: srcs2/ft_%.c $(AUX)
	$(Q)$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LFLAGS) $(LIBS)

build3_%: srcs3/test_%.c $(AUX)
	$(Q)$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LFLAGS) $(LIBS)

%: build1_%
	$(Q)$(PREXEC) $(EXEC) ./run_$@ $(ARGS)
ifeq ($(RMRUN),0)
	$(Q)rm -f ./run_$@
endif

%: build2_%
	@echo --------------------
	$(Q)$(PREXEC) $(EXEC) ./run_$@ $(ARGS)
	@echo --------------------
	@echo "Exit status $$?"
ifeq ($(RMRUN),1)
	$(Q)rm -f ./run_$@
endif
	@echo "Exit status $$?"

%: build3_%
	@echo
	@echo
	@echo =============================
	@echo Starting linked list checks:
	@echo =============================
	@echo
	$(Q)$(PREXEC) $(EXEC) ./run_$@ $(ARGS)
ifeq ($(RMRUN),1)
	$(Q)rm -f ./run_$@
endif

build:	$(addprefix build1_, $(UNITS_01)) \
	$(addprefix build2_, $(UNITS_02)) \
	$(addprefix build3_, $(UNITS_03))

test_%: build2_%
	python $(PROJECTS)/unitests/srcs2/ft_$*.py

clean:
	rm -f $(addprefix run_, $(UNITS_01))
	rm -f $(addprefix run_, $(UNITS_02))
	rm -f $(addprefix run_, $(UNITS_03))

eclean:
	rm -fv compile_commands.json
	bear -- make -B build
	cp -v compile_commands.json srcs1/
	cp -v compile_commands.json srcs2/
	cp -v compile_commands.json srcs3/
	$(MAKE) clean

norm1:
	norminette ft_memory.c ft_random.c \
		$(addsuffix .c, $(addprefix srcs1/ft_, $(UNITS_01)))  | \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS|TOO_MANY_VARS_FUNC" | \
		grep -vE ": OK!"

norm2:
	norminette ft_memory.c ft_random.c \
		$(addsuffix .c, $(addprefix srcs2/ft_, $(UNITS_02)))  | \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS|TOO_MANY_VARS_FUNC" | \
		grep -vE ": OK!"

norm3:
	norminette ft_lists.c ft_random.c \
		$(addsuffix .c, $(addprefix srcs3/test_, $(UNITS_03)))  | \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS|TOO_MANY_VARS_FUNC" | \
		grep -vE ": OK!"

norm: norm1 norm2 norm3

.PHONY: all build eclean clean norm
