/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:26:55 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 22:38:38 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <time.h>

char	*ft_rand_mem(int size);
int		ft_rand(int limit);
char	ft_rand_memval(void);
int		ft_compare_memory(void *truth, void *test, t_size_t size_s, char *src);

/* void *ft_memchr(const void *s, int c, size_t n) */

int	main(void)
{
	char	*str[3];
	int		test_i;
	size_t	sizeof_mem[2];
	int		search;
	int		ret[2];

	srand(time(0));
	test_i = 0;
	while (test_i < 1000)
	{
		sizeof_mem[0] = ft_rand(200) + 1;
		sizeof_mem[1] = ft_rand(200) + 1;
		search = ft_rand_memval();
		str[0] = ft_rand_mem(sizeof_mem[0]);
		str[2] = ft_memchr(str[0], search, sizeof_mem[1]);
		str[1] = memchr(str[0], search, sizeof_mem[1]);
		if (str[1] == NULL && str[2] == NULL)
		{
			free(str[0]);
			continue ;
		}
		ret[0] = ft_compare_memory(str[1], str[2], ft_strlen(str[1]), str[0]);
		ret[1] = ft_compare_memory(str[1], str[2], ft_strlen(str[2]), str[0]);
		if (ret[0] != 1 || ret[1] != 1)
		{
			printf("ft_strchr FAIL: ");
			printf("String s[%s] did not pass the test for char c[%c]:\n",
				str[0], search);
			printf("[%s] (correct)\n[%s] (mine)\n", str[1], str[2]);
			free(str[0]);
			return (1);
		}
		test_i++;
		free(str[0]);
	}
	printf("ft_strchr: PASS\n");
	return (0);
}
