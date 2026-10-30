/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 21:04:49 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:51:59 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <time.h>

char	*ft_rand_str(int size);
int		*ft_rand_array(int size);
int		ft_rand(int limit);
int		ft_compare_bytes(void *truth, void *test, size_t size_s, int val);
int		ft_compare_memory(void *truth, void *test, size_t size_s, char *src);
int		ft_test_string(void);
int		ft_test_array(void);

int	ft_test_string(void)
{
	char	*dest1;
	char	*dest2;
	char	*src;
	int		size_s;
	int		retval;

	size_s = ft_rand(100);
	src = ft_rand_str(size_s);
	dest1 = malloc(size_s * sizeof(char));
	dest2 = malloc(size_s * sizeof(char));
	dest1 = memmove(dest1, src, size_s * sizeof(char));
	dest2 = ft_memmove(dest2, src, size_s * sizeof(char));
	retval = ft_compare_memory(dest1, dest2, size_s * sizeof(char), src);
	if (!retval)
		printf("Problem in strings.\n");
	free(dest1);
	free(dest2);
	free(src);
	return (retval);
}

int	ft_test_array(void)
{
	int	*dest1;
	int	*dest2;
	int	*src;
	int	size_s;
	int	retval;

	size_s = ft_rand(100);
	src = ft_rand_array(2 * size_s);
	dest1 = malloc(2 * size_s * sizeof(int));
	dest2 = malloc(2 * size_s * sizeof(int));
	dest1 = memmove(dest1, src, 2 * size_s * sizeof(int));
	dest2 = ft_memmove(dest2, src, 2 * size_s * sizeof(int));
	retval = ft_compare_memory(dest1, dest2, 2 * size_s * sizeof(int),
			(char *) src);
	free(dest1);
	free(dest2);
	free(src);
	return (retval);
}

int	ft_test_overlap_src_dest(void)
{
	char	*src;
	char	*olap1;
	char	*olap2;
	int		size_s;
	int		retval;

	size_s = ft_rand(100);
	src = ft_rand_str(2 * size_s);
	olap1 = malloc(4 * size_s * sizeof(char));
	olap2 = malloc(4 * size_s * sizeof(char));
	ft_bzero(olap1, 4 * size_s * sizeof(char));
	ft_bzero(olap2, 4 * size_s * sizeof(char));
	olap1 = memmove(olap1, src, 2 * size_s * sizeof(char));
	olap2 = ft_memmove(olap2, src, 2 * size_s * sizeof(char));
	olap1 = memmove(olap1 + size_s, olap1, size_s * sizeof(char));
	olap2 = ft_memmove(olap2 + size_s, olap1, size_s * sizeof(char));
	retval = ft_compare_memory(olap1, olap2, 2 * size_s * sizeof(char), src);
	if (!retval)
		printf("Problem in overlap src before dest.\n");
	free(olap1 - size_s);
	free(olap2 - size_s);
	free(src);
	return (retval);
}

int	ft_test_overlap_dest_src(void)
{
	char	*src;
	char	*olap1;
	char	*olap2;
	int		size_s;
	int		retval;

	size_s = ft_rand(100);
	src = ft_rand_str(2 * size_s);
	olap1 = malloc(4 * size_s * sizeof(char));
	olap2 = malloc(4 * size_s * sizeof(char));
	ft_bzero(olap1, 4 * size_s * sizeof(char));
	ft_bzero(olap2, 4 * size_s * sizeof(char));
	olap1 = memmove(olap1 + size_s, olap1, 2 * size_s * sizeof(char));
	olap2 = ft_memmove(olap2 + size_s, olap1, 2 * size_s * sizeof(char));
	olap1 = memmove(olap1 - size_s, olap1, 2 * size_s * sizeof(char));
	olap2 = ft_memmove(olap2 - size_s, olap1, 2 * size_s * sizeof(char));
	retval = ft_compare_memory(olap1, olap2, 2 * size_s * sizeof(char), src);
	if (!retval)
		printf("Problem in overlap dest before src.\n");
	free(olap1);
	free(olap2);
	free(src);
	return (retval);
}

int	main(void)
{
	int	test_i;

	printf("ft_memmove: ");
	srand(time(0));
	test_i = 0;
	while (test_i < 1000)
	{
		if (!ft_test_string() || !ft_test_array()
			|| !ft_test_overlap_dest_src()
			|| !ft_test_overlap_src_dest())
			return (1);
		test_i++;
	}
	printf("PASS\n");
	return (0);
}
