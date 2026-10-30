/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 14:48:08 by marisous          #+#    #+#             */
/*   Updated: 2026/10/28 14:58:57 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	ichar;

	printf("ft_toupper: ");
	ichar = 0;
	while (ichar < 300)
	{
		if (ft_toupper(ichar) != toupper(ichar))
		{
			printf("FAIL\nProblems with %d %c\n", ichar, ichar);
			return (1);
		}
		ichar++;
	}
	printf("PASS\n");
	return (0);
}
