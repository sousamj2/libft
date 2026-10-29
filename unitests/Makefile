VALG	= 1
ASAN	= 0
DEBUG	= -g -O0

CC	= clang -std=c89 -D_DEFAULT_SOURCE
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I../
LIBS	+= -L.. -lft -lc -lbsd
PREXEC	= ulimit -v 131072; timeout 5s

ifeq ($(VALG),1)
	EXEC	= valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1 -s
	PREXEC	= ulimit -v 262144; timeout 5s
else
	ifeq ($(ASAN),1)
		COMP	= -fsanitize=address,leak
		PREXEC	= timeout 5s env ASAN_OPTIONS=halt_on_error=1
	endif
endif

RAND_UNITS	= 	strlen memset bzero memcpy memmove \
			strlcpy strlcat strchr strrchr \
			strncmp memchr memcmp strnstr

MEMO_UNITS	= 	memset bzero memcpy memmove \
			strlcpy strlcat strchr strrchr \
			memchr memcmp

UNITS	= 	isalpha isdigit isalnum isascii isprint \
		strlen memset bzero memmove \
		strlcpy strlcat toupper tolower \
		strchr strrchr strncmp\
		memchr memcmp strnstr # ...

all: $(UNITS)

test:
	@echo UNITS: $(UNITS)
	@echo RAND_UNITS: $(RAND_UNITS)
	@echo VALG: $(VALG)
	@echo ASAN: $(ASAN)
	@echo EXEC: $(EXEC)
	@echo COMP: $(COMP)
	@echo DEBUG: $(DEBUG)
norm $(addprefix build_, $(RAND_UNITS)): AUX += ft_random.c

norm $(addprefix build_, $(MEMO_UNITS)): AUX += ft_memory.c

build_%: ft_%.c
	$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LIBS)

%: build_%
	$(PREXEC) $(EXEC) ./run_$@
	rm -f ./run_$@

build: $(addprefix build_, $(UNITS))

clean:
	rm -f $(addprefix run_, $(UNITS))

eclean:
	rm -fv compile_commands.json
	bear -- make -B build
	$(MAKE) clean

norm:
	norminette $(addsuffix .c, $(addprefix ft_, $(UNITS))) $(AUX) | \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS"

.PHONY: all build eclean clean norm


