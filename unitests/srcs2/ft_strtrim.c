/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:18:05 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 15:29:46 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(int argc, char *argv[])
{
	char *s1;
	char *set;
	char *res;
	char *exp;
	int debug;

	s1 = "a";
	set = "a";
	exp = "";
	debug = 1;
    if (argc == 3)
    {
		s1 = argv[1];
		set = argv[2];
		debug = 0;
	}
	if (debug)
		printf("\n--------------\n");
	res = ft_strtrim(s1, set);
	if (debug)
{	printf("--------------\n");
	printf("s1: [%s]\nset: [%s]\n", s1, set);
	printf("Expected: [%s]\n", exp);
	printf("Result: [%s]\n", res);
	printf("--------------\n");
}	printf("%s\n", res);
	if (res != NULL)
		free(res);
	return (0);
}
