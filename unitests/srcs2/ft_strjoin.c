/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 11:21:59 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 12:14:53 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(int argc, char *argv[])
{
	char *s1;
	char *s2;
	char *res;

	s1 = "Hello ";
	s2 = "World!";
	
    if (argc >= 3)
    {
		s1 = argv[1];
		s2 = argv[2];
	}
	res = ft_strjoin(s1, s2);
	printf("%s\n", res);
	if (res != NULL)
		free(res);
	return (0);
}
