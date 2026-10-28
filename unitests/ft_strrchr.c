/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:01:05 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 19:11:02 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <time.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);
char	ft_rand_print(void);
int		ft_compare_memory(void *truth, void *test, t_size_t size_s, char *src);

int	main(void)
{
	char	*str[3];
	int		test_i;
	int		sizeof_str;
	char	search;
	int		ret[2];

	srand(time(0));
	test_i = 0;
	while (test_i < 1000)
	{
		sizeof_str = ft_rand(200) + 1;
		search = ft_rand_print();
		str[0] = ft_rand_str(sizeof_str);
		str[1] = strrchr(str[0], search);
		str[2] = ft_strrchr(str[0], search);
		if (str[1] == NULL && str[2] == NULL)
		{
			free(str[0]);
			continue ;
		}
		if (str[1] == NULL && str[2] != NULL)
		{
			printf("str1: %p str2: %p\n", str[1], str[2]);
			printf("str2: %s\n", str[2]);
			free(str[0]);
			return (1);
		}
		if (str[1] != NULL && str[2] == NULL)
		{
			printf("str1: %p str2: %p\n", str[1], str[2]);
			printf("str1: %s\n", str[1]);
			printf("c: %c\tstr0: %s\n", search, str[0]);
			free(str[0]);
			return (1);
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
