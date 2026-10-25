#include <stdio.h>

#include "libft.h"
#include <ctype.h>

int main(void)
{
    printf("Main with no args.\n");
	char *str = "Take1\b\n";

	while (*str != '\0')
	{
		printf("[%c]: [%d] is%s alpha.\n",
			   *str,
			   *str,
			   ft_isalpha(*str) ? "" : " not");
		str++;
	}
	

    return (0);
}
