/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:38:08 by marisous          #+#    #+#             */
/*   Updated: 2026/11/08 15:49:17 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t get_mem_curr();

void	ft_print_list(char **split_list)
{
	char	**tmp;

	tmp = split_list;
	/* if (*split_list == NULL) */
	/* 	printf("NULL\n"); */
	while (*split_list != NULL)
	{
		printf("%s\n", *split_list);
		/* printf("[%p]: [%s]end\n", *split_list, *split_list); */
		fflush(stdout);
		free(*split_list);
		split_list++;
	if (*split_list == NULL)
		printf("NULL\n");
	}
	free(tmp);
}

int	main(int argc, char *argv[])
{
	char	*s;
	char	c;
	char	*exp;
	int		debug;
	char	**res;

	s = "aaa";
	c = 'a';
	exp = "...";
	debug = 1;
	if (argc == 3)
	{
		s = argv[1];
		c = argv[2][0];
		debug = 0;
	}
	res = ft_split(s, c);
	if (debug)
	{
		printf("\n--------------\n");
		if(res == NULL)
			printf("NULL\n");
		else
			printf("res = %p\n", res);
		printf("--------------\n");
		printf("s1: [%s]\nset: [%c]\n", s, c);
		printf("Expected: [%s]\n", exp);
		printf("--------------\n");
	}
	if (res != NULL)
	{	/* printf("----result----------\n"); */
		ft_print_list(res);
		/* printf("--------------\n"); */
	}
	if (debug)
		printf("Current allocation is %lu\n", get_mem_curr());
	
	return (0);
}
