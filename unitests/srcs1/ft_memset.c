/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 15:49:35 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:53:24 by marisous         ###   ########.fr       */
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
int		ft_test_string(void);
int		ft_test_array(void);

int	ft_test_string(void)
{
	char	*str1;
	char	*str2;
	int		size_s;
	int		const_byte;
	int		retval;

	size_s = ft_rand(100);
	const_byte = ft_rand(2048) - 1024;
	str1 = ft_rand_str(size_s);
	str2 = ft_rand_str(size_s);
	str1 = memset(str1, const_byte, size_s * sizeof(char));
	str2 = ft_memset(str2, const_byte, size_s * sizeof(char));
	retval = ft_compare_bytes(str1, str2, size_s * sizeof(char), const_byte);
	if (!retval)
		printf("problem in strings.\n");
	free(str1);
	free(str2);
	return (retval);
}

int	ft_test_array(void)
{
	int	*arr1;
	int	*arr2;
	int	size_s;
	int	const_byte;
	int	retval;

	size_s = ft_rand(100);
	const_byte = ft_rand(2048) - 1024;
	arr1 = ft_rand_array(size_s);
	arr2 = ft_rand_array(size_s);
	arr1 = memset(arr1, const_byte, size_s * sizeof(int));
	arr2 = ft_memset(arr2, const_byte, size_s * sizeof(int));
	retval = ft_compare_bytes(arr1, arr2, size_s * sizeof(int), const_byte);
	if (!retval)
		printf("problem in array of ints.\n");
	free(arr1);
	free(arr2);
	return (retval);
}

int	main(void)
{
	int	test_i;

	printf("ft_memset");
	srand(time(0));
	test_i = 0;
	while (test_i < 100)
	{
		if (!ft_test_string() || !ft_test_array())
			return (1);
		test_i++;
	}
	printf(": PASS\n");
	return (0);
}
