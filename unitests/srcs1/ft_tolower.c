/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:57:09 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 14:58:36 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	ichar;

	printf("ft_tolower: ");
	ichar = 0;
	while (ichar < 300)
	{
		if (ft_tolower(ichar) != tolower(ichar))
		{
			printf("FAIL\nProblems with %d %c\n", ichar, ichar);
			return (1);
		}
		ichar++;
	}
	printf("PASS\n");
	return (0);
}
