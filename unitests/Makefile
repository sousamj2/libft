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


RAND_UNITS_02	= 	strjoin strtrim substr

MEMO_UNITS_02	= 	

UNITS_02	= 	strjoin strtrim substr

all: $(UNITS_01) $(UNITS_02)

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
	@echo --------------------
	@echo Using random.c
	@echo --------------------
	@echo RAND_UNITS_01: $(RAND_UNITS_01)
	@echo RAND_UNITS_02: $(RAND_UNITS_02)
	@echo --------------------

norm $(addprefix build1_, $(RAND_UNITS_01)) \
norm $(addprefix build2_, $(RAND_UNITS_02)) : AUX += ft_random.c

norm $(addprefix build1_, $(MEMO_UNITS_01)) \
norm $(addprefix build2_, $(MEMO_UNITS_02)) : AUX += ft_memory.c

build1_%: srcs1/ft_%.c
	$(Q)$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LIBS)

build2_%: srcs2/ft_%.c
	$(Q)$(CC) $(CFLAGS) $(DEBUG) $(COMP) $(AUX) $< -o ./run_$* $(LIBS)

%: build1_%
	$(Q)$(PREXEC) $(EXEC) ./run_$@
	$(Q)rm -f ./run_$@

%: build2_%
	$(Q)$(PREXEC) $(EXEC) ./run_$@
	$(Q)rm -f ./run_$@

build: $(addprefix build1_, $(UNITS_01)) $(addprefix build2_, $(UNITS_02))

clean:
	rm -f $(addprefix run_, $(UNITS_01))
	rm -f $(addprefix run_, $(UNITS_02))

eclean:
	rm -fv compile_commands.json
	bear -- make -B build
	cp -v compile_commands.json srcs1/
	cp -v compile_commands.json srcs2/
	$(MAKE) clean

norm1:
	norminette $(AUX) \
		$(addsuffix .c, $(addprefix ft_, $(UNITS_01)))  \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS|TOO_MANY_VARS_FUNC" | \
		grep -vE ": OK!"

norm2:
	norminette $(AUX) \
		$(addsuffix .c, $(addprefix ft_, $(UNITS_02)))  \
		grep -vE "TOO_MANY_LINES|TOO_MANY_FUNCS|TOO_MANY_VARS_FUNC" | \
		grep -vE ": OK!"

norm: norm1 norm2

.PHONY: all build eclean clean norm


