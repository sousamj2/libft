/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 19:28:46 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:37:04 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_rand_str(int size);
int		ft_rand(int limit);
char	ft_rand_print(void);
char	*ft_rand_str_small(int size_str, int size_mem);

int	ft_rand(int limit)
{
	return (rand() % limit);
}

char	ft_rand_print(void)
{
	char	ret;

	ret = 0;
	while (1)
	{
		ret = ft_rand(256);
		if (ft_isprint(ret))
			break ;
	}
	return (ret);
}

char	ft_rand_memval(void)
{
	return (ft_rand(256));
}

char	*ft_rand_str_small(int size_str, int size_mem)
{
	char	*str;
	int		index;

	index = 0;
	str = malloc((size_mem + 1) * sizeof(char));
	while (index < size_str)
	{
		str[index] = ft_rand_print();
		index++;
	}
	str[index] = '\0';
	return (str);
}

char	*ft_rand_str(int size)
{
	char	*str;
	int		index;

	index = 0;
	str = malloc((size + 1) * sizeof(char));
	while (index < size)
	{
		str[index] = ft_rand_print();
		index++;
	}
	str[index] = '\0';
	return (str);
}

void	*ft_rand_mem(int size)
{
	unsigned char	*str;
	int				index;

	index = 0;
	str = malloc(size);
	while (index < size)
	{
		str[index] = ft_rand_memval();
		index++;
	}
	return (str);
}

char	ft_rand_elem(const char *list, int lsize)
{
	return (list[ft_rand(lsize)]);
}

size_t	ft_rand_elem_size(const size_t *list, int lsize)
{
	return (list[ft_rand(lsize)]);
}

char	*ft_rand_atoi(size_t nspaces, size_t ndigs)
{
	size_t		ispace;
	size_t		idig;
	size_t		iafter;
	size_t		after_num;
	char		*retval;
	const char	spacechars[6] = {' ', '\f', '\n', '\r', '\t', '\v'};
	const char	signchars[3] = {' ', '-', '+'};

	idig = 0;
	ispace = 0;
	iafter = 0;
	after_num = ft_rand(4);
	retval = malloc((nspaces + ndigs + after_num + 2) * sizeof(char));
	while (ispace < nspaces)
	{
		retval[ispace] = ft_rand_elem(spacechars, 6);
		retval[ispace + 1] = '\0';
		ispace++;
	}
	retval[nspaces] = ft_rand_elem(signchars, 3);
	retval[nspaces + 1] = '\0';
	while (idig < ndigs)
	{
		retval[nspaces + idig + 1] = '0' + ft_rand(10);
		retval[nspaces + idig + 2] = '\0';
		idig++;
	}
	while (iafter < after_num)
	{
		retval[nspaces + ndigs + iafter + 1] = ft_rand_print();
		retval[nspaces + ndigs + iafter + 2] = '\0';
		iafter++;
	}
	return (retval);
}

int	*ft_rand_array(int size)
{
	int	*array;
	int	index;

	index = 0;
	array = malloc((size) * sizeof(int));
	while (index < size)
	{
		array[index] = rand() - RAND_MAX + rand();
		index++;
	}
	return (array);
}
