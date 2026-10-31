/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 12:18:05 by marisous          #+#    #+#             */
/*   Updated: 2026/10/31 13:06:22 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int main(int argc, char *argv[])
{
	char *s1;
	char *set;
	char *res;

	s1 = " ";
	set = " ";
	
    if (argc >= 3)
    {
		s1 = argv[1];
		set = argv[2];
	}
	printf("\n--------------\n");	
	res = ft_strtrim(s1, set);
	printf("--------------\n");	
	printf("s1: [%s]\nset: [%s]\n", s1, set);
	printf("Expected: [%s] with size [%lu]\n", "Heo ", ft_strlen("Heo "));
	printf("Result: [%s]\n", res);
	printf("--------------\n");	
	/* printf("%s\n", res); */
	if (res != NULL)
		free(res);
	return (0);
}
