/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 18:38:08 by marisous          #+#    #+#             */
/*   Updated: 2026/11/01 01:09:30 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_print_list(char **split_list)
{
	char	**tmp;

	tmp = split_list;
	while (*split_list != NULL)
	{
		printf("%s\n", *split_list);
		free(*split_list);
		split_list++;
	}
	free(tmp);
}

int	main(int argc, char *argv[])
{
	char	*s;
	char	c;
	char	*exp;
	int		debug;
	char	**res;

	s = "7CJAKVIkdmEbZAgtqlLEO2j0K8acjyNcsZgQ1wdo1Tm9O2Rt0nHENxr51nKTRWJz80";
	c = 'a';
	exp = "'b', 'b', 'b', 'b'";
	debug = 0;
	if (argc == 3)
	{
		s = argv[1];
		c = argv[2][0];
		debug = 0;
	}
	if (debug)
	{
		printf("\n--------------\n");
		printf("--------------\n");
		printf("s1: [%s]\nset: [%c]\n", s, c);
		printf("Expected: [%s]\n", exp);
		printf("--------------\n");
	}
	res = ft_split(s, c);
	if (res != NULL)
		ft_print_list(res);
	return (0);
}
