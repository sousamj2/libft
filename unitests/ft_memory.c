/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:15:46 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:53:32 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_compare_bytes(void *truth, void *test, size_t size_s, int val)
{
	size_t		index;
	unsigned char	*ptr_tru;
	unsigned char	*ptr_tes;

	index = 0;
	ptr_tes = test;
	ptr_tru = truth;
	while (index < size_s)
	{
		if (*ptr_tes != *ptr_tru || *ptr_tes != (unsigned char) val)
		{
			printf("test [%ud] truth [%ud] val [%ud]\n",
				*ptr_tes, *ptr_tru, (unsigned char) val);
			return (0);
		}
		index++;
		ptr_tru++;
		ptr_tes++;
	}
	return (1);
}

int	ft_compare_memory(void *truth, void *test, size_t size_s, char *src)
{
	size_t		index;
	unsigned char	*ptr_tru;
	unsigned char	*ptr_tes;

	index = 0;
	ptr_tes = test;
	ptr_tru = truth;
	while (index < size_s)
	{
		if (*ptr_tes != *ptr_tru)
		{
			printf("  src: [%p] %s\n", src, src);
			return (0);
		}
		index++;
		ptr_tru++;
		ptr_tes++;
	}
	return (1);
}

/* printf("Size is: %d\n", (int) size_s); */
/* printf("index [%d] test [%d] truth [%d]\n", */
/* 	(int) index, (int) *ptr_tes, (int) *ptr_tru); */
/* printf("index [%d] test [%d] truth [%d]\n", */
/* 	(int) index + 1, (int) *(ptr_tes + 1), (int)*(ptr_tru + 1)); */
/* printf("index [%d] test [%d] truth [%d]\n", */
/* 	(int)size_s - 1, */
/* 	(int)*(ptr_tes + size_s - 1), */
/* 	(int)*(ptr_tru + size_s - 1)); */
/* printf("index [%d] test [%d] truth [%d]\n", */
/* 	(int) size_s, */
/* 	(int) *(ptr_tes + size_s), */
/* 	(int) *(ptr_tru + size_s)); */
