/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 09:50:22 by marisous          #+#    #+#             */
/*   Updated: 2026/11/01 09:50:22 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*number_str;
	int		number_int;
	char	*result;
	int		debug;

	debug = 0;
	number_str = "-2147483648";
	if (argc > 1)
	{
		number_str = argv[1];
		debug = 0;
	}
	number_str = ft_strtrim(number_str, " ");
	number_int = ft_atoi(number_str);
	result = ft_itoa(number_int);
	if (ft_strncmp(number_str, result, ft_strlen(result)) || debug)
		printf("Number i [%d] str [%s] result [%s].\n",
			number_int, number_str, result);
	else
		printf("Correct.");
	free(result);
	free(number_str);
	return (0);
}
