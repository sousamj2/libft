/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 08:33:18 by marisous          #+#    #+#             */
/*   Updated: 2026/10/27 13:09:08 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <strings.h>
#include <time.h>
#include <bsd/bsd.h>

char	*ft_rand_str(int size);
char	*ft_rand_str_small(int size_str, int size_mem);
int		*ft_rand_array(int size);
int		ft_rand(int limit);
int		ft_compare_bytes(void *truth, void *test, t_size_t size_s, int val);
int		ft_compare_memory(void *truth, void *test, t_size_t size_s, char *src);
int		ft_test_samesize(void);

int	ft_test_exactsize(void)
{
	char	*dest[2];
	char	*src;
	int		size_s[3];
	int		retval;
	size_t	ret[2];

	size_s[0] = ft_rand(10) + 1;
	src = ft_rand_str(size_s[0]);
	size_s[1] = ft_rand(10) + 1;
	dest[0] = ft_rand_str_small(size_s[1], (size_s[0] + size_s[1]));
	dest[1] = malloc((size_s[0] + size_s[1] + 1) * sizeof(char));
	size_s[2] = ft_strlcpy(dest[1], dest[0], size_s[0] + size_s[1]);
	ret[0] = strlcat(dest[0], src, (size_s[0] + size_s[1] + 1));
	ret[1] = ft_strlcat(dest[1], src, (size_s[0] + size_s[1]));
	retval = ft_compare_memory(dest[0], dest[1],
			(size_s[0] + size_s[1] + 1) * sizeof(char), src);
	if (!retval || ret[0] != ret[1])
	{
		printf("Problem in 0 size src strings.\n");
		printf("retval: %d, ret0: %ld, ret1: %ld\n", retval, ret[0], ret[1]);
		printf("src : %s\n", src);
		printf("dst1: %s\n", dest[0]);
		printf("dst2: %s\n", dest[1]);
	}
	free(dest[0]);
	free(dest[1]);
	free(src);
	return (retval);
}


int	ft_test_zerodst(void)
{
	char	*dest[2];
	char	*src;
	int		size_s[3];
	int		retval;
	size_t	ret[2];

	size_s[0] = ft_rand(100) + 1;
	src = ft_rand_str(size_s[0]);
	size_s[1] = 0;
	dest[0] = ft_rand_str_small(size_s[1], (size_s[0] + size_s[1]));
	dest[1] = malloc((size_s[0] + size_s[1] + 1) * sizeof(char));
	size_s[2] = ft_strlcpy(dest[1], dest[0], size_s[0] + size_s[1]);
	ret[0] = strlcat(dest[0], src, (size_s[0] + size_s[1] + 1));
	ret[1] = ft_strlcat(dest[1], src, (size_s[0] + size_s[1]));
	retval = ft_compare_memory(dest[0], dest[1],
			(size_s[0] + size_s[1] + 1) * sizeof(char), src);
	if (!retval || ret[0] != ret[1])
	{
		printf("Problem in 0 size dst strings.\n");
		printf("retval: %d, ret0: %ld, ret1: %ld\n", retval, ret[0], ret[1]);
		printf("src : %s\n", src);
		printf("dst1: %s\n", dest[0]);
		printf("dst2: %s\n", dest[1]);
	}
	free(dest[0]);
	free(dest[1]);
	free(src);
	return (retval);
}


int	ft_test_zerosrc(void)
{
	char	*dest[2];
	char	*src;
	int		size_s[3];
	int		retval;
	size_t	ret[2];

	size_s[0] = 0;
	src = ft_rand_str(size_s[0]);
	size_s[1] = ft_rand(50) + 1;
	dest[0] = ft_rand_str_small(size_s[1], (size_s[0] + size_s[1]));
	dest[1] = malloc((size_s[0] + size_s[1] + 1) * sizeof(char));
	size_s[2] = ft_strlcpy(dest[1], dest[0], size_s[0] + size_s[1]);
	ret[0] = strlcat(dest[0], src, (size_s[0] + size_s[1] + 1));
	ret[1] = ft_strlcat(dest[1], src, (size_s[0] + size_s[1] + 1));
	retval = ft_compare_memory(dest[0], dest[1],
			(size_s[0] + size_s[1] + 1) * sizeof(char), src);
	if (!retval || ret[0] != ret[1])
	{
		printf("Problem in 0 size src strings.\n");
		printf("retval: %d, ret0: %ld, ret1: %ld\n", retval, ret[0], ret[1]);
		printf("src : %s\n", src);
		printf("dst1: %s\n", dest[0]);
		printf("dst2: %s\n", dest[1]);
		
	}
	free(dest[0]);
	free(dest[1]);
	free(src);
	return (retval);
}

int	main(void)
{
	int	test_i;

	printf("ft_strlcat: ");
	srand(time(0));
	test_i = 0;
	while (test_i < 100)
	{
		if (!ft_test_exactsize() || !ft_test_zerosrc() || !ft_test_zerodst())
			return (1);
		test_i++;
	}
	printf("PASS\n");
	return (0);
}
