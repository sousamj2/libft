VALG	= 1
ASAN	= 0
DEBUG	= -g -O0
QUIET	= 0
Q = $(if $(filter 1,$(QUIET)),@,)

CC	= clang -std=c89 -D_DEFAULT_SOURCE
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I..
LIBS	+= -L.. -lft -lc -lbsd
PREXEC	= ulimit -v 131072; timeout 5s

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

all: $(UNITS_01)

test:
	@echo UNITS_01: $(UNITS_01)
	@echo RAND_UNITS_01: $(RAND_UNITS_01)
	@echo VALG: $(VALG)
	@echo ASAN: $(ASAN)
	@echo EXEC: $(EXEC)
	@echo COMP: $(COMP)
	@echo DEBUG: $(DEBUG)

norm $(addprefix build1_, $(RAND_UNITS_01)): AUX += ft_random.c

norm $(addprefix build1_, $(MEMO_UNITS_01)): AUX += ft_memory.c

build1_%: srcs1/ft_%.c
	$(Q)$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LIBS)

%: build1_%
	$(Q)$(PREXEC) $(EXEC) ./run_$@
	$(Q)rm -f ./run_$@

build: $(addprefix build1_, $(UNITS_01))

clean:
	rm -f $(addprefix run_, $(UNITS_01))

eclean:
	rm -fv compile_commands.json
	bear -- make -B build
	$(MAKE) clean

norm:
	norminette $(addsuffix .c, $(addprefix ft_, $(UNITS_01))) $(AUX) | \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS|TOO_MANY_VARS_FUNC" | \
		grep -vE ": OK!"

.PHONY: all build eclean clean norm


