/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:28:51 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:53:01 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include "libft.h"

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
	int		retval;

	size_s = ft_rand(100);
	str1 = ft_rand_str(size_s);
	str2 = ft_rand_str(size_s);
	bzero(str1, size_s * sizeof(char));
	ft_bzero(str2, size_s * sizeof(char));
	retval = ft_compare_bytes(str1, str2, size_s * sizeof(char), 0);
	free(str1);
	free(str2);
	if (!retval)
		printf("problem in strings.\n");
	return (retval);
}

int	ft_test_array(void)
{
	int	*arr1;
	int	*arr2;
	int	size_s;
	int	retval;

	size_s = ft_rand(100);
	arr1 = ft_rand_array(size_s);
	arr2 = ft_rand_array(size_s);
	bzero(arr1, size_s * sizeof(int));
	ft_bzero(arr2, size_s * sizeof(int));
	retval = ft_compare_bytes(arr1, arr2, size_s * sizeof(int), 0);
	free(arr1);
	free(arr2);
	if (!retval)
		printf("problem in array of ints.\n");
	return (retval);
}

int	main(void)
{
	int	test_i;

	printf("ft_bzero");
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
