/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 19:30:35 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 22:17:07 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

int	ft_same_string(char *s1)
{
	char	*s2;
	int		ret1;
	int		ret2;

	s2 = s1;
	ret1 = strncmp(s1, s2, strlen(s1));
	ret2 = ft_strncmp(s1, s2, ft_strlen(s1));
	return (ret1 == ret2);
}

int	ft_two_strings(char *s1, char *s2, size_t n)
{
	int	ret1;
	int	ret2;

	s2 = s1;
	ret1 = strncmp(s1, s2, n);
	ret2 = ft_strncmp(s1, s2, n);
	if (ret1 != ret2)
		printf("s1[%s] s2[%s]\n", s1, s2);
	return (ret1 == ret2);
}

int	main(void)
{
	char	*str;
	int		test_i;
	int		sizeof_str;

	srand(time(0));
	test_i = 0;
	while (test_i < 100)
	{
		sizeof_str = ft_rand(100);
		str = ft_rand_str(sizeof_str);
		if (!ft_same_string(str))
		{
			printf("ft_strncmp FAIL: ");
			printf("String s[%s] did not pass the test.\n", str);
			free(str);
			return (1);
		}
		test_i++;
		free(str);
	}
	if (!ft_two_strings("aaa", "aaab", 5) || !ft_two_strings("aaa", "aaab", 4)
		|| !ft_two_strings("aaa", "aaab", 3) || !ft_two_strings("aab", "abb", 3)
		|| !ft_two_strings("aca", "aab", 3) || !ft_two_strings("daa", "aaab", 3)
		|| !ft_two_strings("aaa", "aaab", 3) || !ft_two_strings("", "aaab", 3)
		|| !ft_two_strings("aaa", "", 3) || !ft_two_strings("aaa", "aaab", 0)
		|| !ft_two_strings("", "", 3))
		return (1);
	printf("ft_strlen: PASS\n");
	return (0);
}
