/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 16:27:35 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:53:40 by marisous         ###   ########.fr       */
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
int		ft_compare_memory(void *truth, void *test, size_t size_s, char *src);

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
		str[2] = ft_strchr(str[0], search);
		str[1] = strchr(str[0], search);
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
