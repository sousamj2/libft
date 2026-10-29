/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:17:32 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 11:59:13 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/bsd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_n_is_len_s2(size_t n)
{
	char	*str[2];
	size_t	sizeof_str;
	char	*ret[2];

	sizeof_str = ft_rand(n);
	str[0] = ft_rand_str(sizeof_str);
	str[1] = ft_rand_str(1);
	ret[0] = strnstr(str[0], str[1], sizeof_str);
	ret[1] = ft_strnstr(str[0], str[1], sizeof_str);
	if (ret[0] != ret[1])
	{
		printf("ft_strnstr: FAIL\n");
		printf("ret0 [%p] ret1 [%p]\n", ret[0], ret[1]);
		printf("s1[%p]: [%s]\n", str[0], str[0]);
		printf("s2[%p]: [%s]\n", str[1], str[1]);
		printf("size ret1 [%lu]\n", ft_strlen(ret[1]));
		printf("size str0 [%lu]\n", ft_strlen(str[0]));
		printf("\n");
		if (ret[1])
			printf("ret1 [%s]\n", ret[1]);
		if (ret[0])
			printf("ret1 [%s]\n", ret[0]);
		printf("\n");
		printf("\n");
		free(str[0]);
		free(str[1]);
		return (0);
	}
	free(str[0]);
	free(str[1]);
	return (ret[0] == ret[1]);
}

int	main(void)
{
	int		test_i;

	srand(time(0));
	test_i = 0;
	while (test_i < 10000)
	{
		if (!ft_n_is_len_s2(100))
		{
			return (1);
		}
		test_i++;
	}
	printf("ft_strnstr: PASS\n");
	return (0);
}
