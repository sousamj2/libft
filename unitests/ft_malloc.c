/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:50:33 by marisous          #+#    #+#             */
/*   Updated: 2026/11/08 15:13:18 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifndef CHECK_MEM_NUM
# define CHECK_MEM_NUM 10
#endif
static size_t n_mem = 0;
static size_t n_mem_curr = 0;

void *__real_malloc(size_t size);
void __real_free(void *ptr);

void *__wrap_malloc(size_t size)
{
#ifdef CHECK_MEM_NUM
	if (CHECK_MEM_NUM > 0 && n_mem_curr + 1 > CHECK_MEM_NUM)
		return (NULL);
#endif
	void *retval = __real_malloc(size);
	if (retval == NULL)
		return (NULL);
	n_mem += 1;
	n_mem_curr += 1;
	return (retval);
}

void __wrap_free(void *ptr)
{
	if (ptr != NULL)
		n_mem_curr -= 1;
	__real_free(ptr);
}

size_t get_mem_curr()
{
	return(n_mem_curr);
}	
