/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 21:01:50 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 22:14:56 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);

void	ft_free_mem(void *str, void *dup0, void *dup1)
{
	if (str != NULL)
		free(str);
	if (dup0 != NULL)
		free(dup0);
	if (dup1 != NULL)
		free(dup1);
}

int	main(void)
{
	char	*str;
	char	*dup[2];
	int		test_i;
	int		sizeof_str;
	int		cmp[2];

	srand(time(0));
	test_i = 0;
	while (test_i < 200)
	{
		sizeof_str = ft_rand(100) + 1;
		str = ft_rand_str(sizeof_str);
		dup[0] = strdup(str);
		dup[1] = ft_strdup(str);
		cmp [0] = strncmp(str, dup[0], sizeof_str);
		cmp [1] = ft_strncmp(str, dup[1], sizeof_str);
		if (cmp [0] != cmp [1])
		{
			printf("ft_strdup FAIL: ");
			printf("String s[%s] did not pass the test.\n", str);
			ft_free_mem(str, dup[0], dup[1]);
			return (1);
		}
		test_i++;
		ft_free_mem(str, dup[0], dup[1]);
	}
	printf("ft_strdup: PASS\n");
	return (0);
}

/* /\* Test for NULL string *\/ */
/* str = NULL; */
/* dup[0] = NULL; */
/* dup[0] = strdup(str); */
/* dup[1] = NULL; */
/* dup[1] = ft_strdup(str);  */

/* /\* Test for empty string *\/ */
/* str = ""; */
/* dup[0] = NULL; */
/* dup[0] = strdup(str); */
/* dup[1] = NULL; */
/* dup[1] = ft_strdup(str);  */
