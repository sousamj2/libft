/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 15:29:18 by marisous          #+#    #+#             */
/*   Updated: 2026/11/01 15:29:18 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	ft_identity(unsigned int index, char c)
{
	if (index == 0)
		return (c);
	else
		return (c);
}

char	ft_upper(unsigned int index, char c)
{
	if (index == 0)
		return (ft_toupper(c));
	else
		return (ft_toupper(c));
}

char	ft_lower(unsigned int index, char c)
{
	if (index == 0)
		return (ft_tolower(c));
	else
		return (ft_tolower(c));
}

char	ft_odd_up_even_down(unsigned int index, char c)
{
	if (index % 2 == 1)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}

char	ft_up1_down2_id3(unsigned int index, char c)
{
	if (index % 3 == 1)
		return (ft_toupper(c));
	else if (index % 3 == 2)
		return (ft_tolower(c));
	else
		return (c);
}

int	main(int argc, char *argv[])
{
	int		option;
	char	*str;
	char	*result;

	option = 0;
	str = "Hello World!";
	if (argc == 3)
	{
		option = ft_atoi(argv[1]);
		str = argv[2];
	}
	if (option == 1)
		result = ft_strmapi(str, ft_lower);
	else if (option == 2)
		result = ft_strmapi(str, ft_upper);
	else if (option == 3)
		result = ft_strmapi(str, ft_odd_up_even_down);
	else if (option == 4)
		result = ft_strmapi(str, ft_up1_down2_id3);
	else
		result = ft_strmapi(str, ft_identity);
	printf("%s", result);
	free(result);
	return (0);
}
