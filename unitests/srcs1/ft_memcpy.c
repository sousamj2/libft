/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:12:43 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:51:51 by marisous         ###   ########.fr       */
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
int		ft_compare_memory(void *truth, void *test, size_t size_s);
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
	dest1 = memcpy(dest1, src, size_s * sizeof(char));
	dest2 = ft_memcpy(dest2, src, size_s * sizeof(char));
	retval = ft_compare_memory(dest1, dest2, size_s * sizeof(char));
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
	src = ft_rand_array(size_s);
	dest1 = malloc(size_s * sizeof(int));	
	dest2 = malloc(size_s * sizeof(int));	
	dest1 = memcpy(dest1, src, size_s * sizeof(int));
	dest2 = ft_memcpy(dest2, src, size_s * sizeof(int));
	retval = ft_compare_memory(dest1, dest2, size_s * sizeof(int));
	free(dest1);
	free(dest2);
	free(src);
	return (retval);
}

int	main(void)
{
	int	test_i;
	printf("ft_memcpy: ");

	srand(time(0));
	test_i = 0;
	while (test_i < 100)
	{
		if (!ft_test_string() || !ft_test_array())
			return (1);
		test_i++;
	}
	printf("PASS\n");
	return (0);
}
