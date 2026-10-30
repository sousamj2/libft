/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 15:14:25 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 18:45:51 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);
char	*ft_rand_atoi(size_t nspaces, size_t ndigs);

int	ft_edge_cases(void)
{
	int			iedge;
	int			atois [2];
	const char	*edges[] = {
		"0", "000000000000000000001", "000000000000000000000",
		"-9223372036854775807", "+2147483649", "\f-42a",
		"-9223372036854775808", "+2147483648", "\n+42b",
		"-9223372036854775809", " 2147483647", "\t 42c",
		"+9223372036854775807", "-2147483649", "\v+42d",
		" 9223372036854775808", "-2147483648", "\r 42e",
		" 9223372036854775809", "-2147483647", " -42f",
		"+555", "-1"};

	iedge = 0;
	while (iedge < 23)
	{
		atois[0] = atoi(edges[iedge]);
		atois[1] = ft_atoi(edges[iedge]);
		if (atois[0] != atois[1])
		{
			printf("   ATOI\n [%s] -> [%d]\n", edges[iedge], atois[0]);
			printf("FT_ATOI\n [%s] -> [%d]\n", edges[iedge], atois[1]);
			printf("\n");
			return (0);
		}
		iedge++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		nspaces;
	int		ndigs;
	int		i_test;
	int		atois [2];
	char	*rand_string;

	srand(time(0));
	if (argc > 1)
	{
		printf("   ATOI [%s] -> [%d]\n", argv[1], atoi(argv[1]));
		printf("FT_ATOI [%s] -> [%d]\n", argv[1], ft_atoi(argv[1]));
		return (0);
	}
	i_test = 0;
	if (!ft_edge_cases())
		return (1);
	while (i_test < 200)
	{
		nspaces = ft_rand(10);
		ndigs = ft_rand(40);
		rand_string = ft_rand_atoi(nspaces, ndigs);
		atois[0] = atoi(rand_string);
		atois[1] = ft_atoi(rand_string);
		if (atois[0] != atois[1])
		{
			printf("   ATOI\n [%s] -> [%d]\n", rand_string, atois[0]);
			printf("FT_ATOI\n [%s] -> [%d]\n", rand_string, atois[1]);
			free(rand_string);
			printf("\n");
			return (1);
		}
		free(rand_string);
		i_test++;
	}
	return (0);
}
