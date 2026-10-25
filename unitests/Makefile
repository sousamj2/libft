VALG	= 0 # Use 1 to run valgrind and 0 otherwise
ASAN	= 1 # Use 1 to run address and leak sanitization. 0 otherwise.
# DEBUG	= -g -O0 # Comment if you don't want to run debug mode.

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I../
LIBS	+= -L.. -lft -lc
PREXEC	= ulimit -v 10240; timeout 5s 

ifeq ($(VALG),1)
	EXEC	= valgrind --leak-check=full --error-exitcode=1
else
	ifeq ($(ASAN),1)
		COMP	= -fsanitize=address,leak
		PREXEC	+= ASAN_OPTIONS=halt_on_error=1
	endif
endif

UNITS	= isalpha isdigit isalnum # ...

all: $(UNITS)

build_%: ft_%.c
	$(CC) $(CFLAGS) $(DEBUG) $(COMP) $< -o ./run_$* $(LIBS)

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

.PHONY: all build eclean clean
