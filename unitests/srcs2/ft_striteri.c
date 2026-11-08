/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 16:50:21 by marisous          #+#    #+#             */
/*   Updated: 2026/11/08 15:52:49 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_identity(unsigned int index, char *c)
{
	if (*c + index == 'a')
		return ;
	else
		return ;
}

void	ft_upper(unsigned int index, char *c)
{
	if (index == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_toupper(*c);
}

void	ft_lower(unsigned int index, char *c)
{
	if (index == 0)
		*c = ft_tolower(*c);
	else
		*c = ft_tolower(*c);
}

void	ft_odd_up_even_down(unsigned int index, char *c)
{
	if (index % 2 == 1)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

void	ft_up1_down2_id3(unsigned int index, char *c)
{
	if (index % 3 == 1)
		*c = ft_toupper(*c);
	else if (index % 3 == 2)
		*c = ft_tolower(*c);
}

int	main(int argc, char *argv[])
{
	int		option;
	char	*str;

	option = 0;
	str = "Hello World!";
	if (argc == 3)
	{
		option = ft_atoi(argv[1]);
		str = argv[2];
	}
	if (option == 1)
		ft_striteri(str, ft_lower);
	else if (option == 2)
		ft_striteri(str, ft_upper);
	else if (option == 3)
		ft_striteri(str, ft_odd_up_even_down);
	else if (option == 4)
		ft_striteri(str, ft_up1_down2_id3);
	else
		ft_striteri(str, ft_identity);
	printf("%s", str);
	return (0);
}
