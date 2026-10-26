/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:15:46 by marisous          #+#    #+#             */
/*   Updated: 2026/10/26 18:48:24 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_compare_bytes(void *truth, void *test, t_size_t size_s, int val)
{
	t_size_t		index;
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

int	ft_compare_memory(void *truth, void *test, t_size_t size_s)
{
	t_size_t		index;
	unsigned char	*ptr_tru;
	unsigned char	*ptr_tes;

	index = 0;
	ptr_tes = test;
	ptr_tru = truth;
	while (index < size_s)
	{
		if (*ptr_tes != *ptr_tru)
		{
			printf("test [%ud] truth [%ud]\n",
				*ptr_tes, *ptr_tru);
			return (0);
		}
		index++;
		ptr_tru++;
		ptr_tes++;
	}
	return (1);
}
