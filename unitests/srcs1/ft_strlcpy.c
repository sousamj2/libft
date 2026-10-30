/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 07:14:26 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:52:34 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <bsd/bsd.h>
#include "libft.h"

char	*ft_rand_str(int size);
int		*ft_rand_array(int size);
int		ft_rand(int limit);
int		ft_compare_bytes(void *truth, void *test, size_t size_s, int val);
int		ft_compare_memory(void *truth, void *test, size_t size_s);
int		ft_test_samesize(void);

int	ft_test_samesize(void)
{
	char	*dest[2];
	char	*src;
	int		size_s;
	int		retval;
	size_t	ret[2];

	size_s = ft_rand(100) + 1;
	src = ft_rand_str(size_s - 1);
	dest[0] = malloc(size_s * sizeof(char));
	dest[1] = malloc(size_s * sizeof(char));
	bzero(dest[0], size_s * sizeof(char));
	ft_bzero(dest[1], size_s * sizeof(char));
	ret[0] = strlcpy(dest[0], src, size_s * sizeof(char));
	ret[1] = ft_strlcpy(dest[1], src, size_s * sizeof(char));
	retval = ft_compare_memory(dest[0], dest[1], size_s * sizeof(char));
	if (!retval || ret[0] != ret[1])
		printf("Problem in same size strings.\n");
	free(dest[0]);
	free(dest[1]);
	free(src);
	return (retval);
}

int	ft_test_diffsize(void)
{
	char	*dest[2];
	char	*src;
	int		size_s;
	int		retval;
	size_t	ret[2];

	size_s = ft_rand(100);
	src = ft_rand_str(size_s);
	size_s = ft_rand(100) + 1;
	dest[0] = malloc(size_s * sizeof(char));
	dest[1] = malloc(size_s * sizeof(char));
	bzero(dest[0], size_s * sizeof(char));
	ft_bzero(dest[1], size_s * sizeof(char));
	ret[0] = strlcpy(dest[0], src, size_s * sizeof(char));
	ret[1] = ft_strlcpy(dest[1], src, size_s * sizeof(char));
	retval = ft_compare_memory(dest[0], dest[1], size_s * sizeof(char));
	if (!retval || ret[0] != ret[1])
	{
		printf("Problem in different size strings.\n");
		printf("retval: %d, ret0: %ld, ret1: %ld\n", retval, ret[0], ret[1]);
	}
	free(dest[0]);
	free(dest[1]);
	free(src);
	return (retval);
}

int	main(void)
{
	int	test_i;

	printf("ft_strlcpy: ");
	srand(time(0));
	test_i = 0;
	while (test_i < 200)
	{
		if (!ft_test_samesize() || !ft_test_diffsize())
			return (1);
		test_i++;
	}
	printf("PASS\n");
	return (0);
}
