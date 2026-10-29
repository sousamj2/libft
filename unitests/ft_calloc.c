/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:25:38 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 20:03:55 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 19:19:10 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 19:24:49 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_rand_elem_size(const size_t *list, int lsize);
int		ft_rand(int limit);

int	main(void)
{
	size_t			size;
	size_t			n;
	int				i_test;
	void			*ptr;
	const size_t	varsizes[6] = {sizeof(int),
		sizeof(char),
		sizeof(int *),
		sizeof(size_t),
		sizeof(char **),
		sizeof(t_list)};

	i_test = 0;
	while (i_test < 200)
	{
		size = ft_rand_elem_size(varsizes, 6);
		n = ft_rand(100);
		ptr = ft_calloc(n, size);
		free(ptr);
		i_test++;
	}
	printf("ft_calloc: PASS\n");
	return (0);
}
