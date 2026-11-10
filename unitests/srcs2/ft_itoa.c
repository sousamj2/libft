/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 09:50:22 by marisous          #+#    #+#             */
/*   Updated: 2026/11/03 13:41:52 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_itoa_mem(long *n_long, int *negative, size_t *nchars)
{
	char	*retval;
	long	n_longcopy;

	*negative = 0;
	*nchars = 1;
	if (*n_long <= 0)
		(*nchars)++;
	if (*n_long < 0)
	{
		*n_long *= -1;
		*negative = 1;
	}
	n_longcopy = *n_long;
	while (n_longcopy > 0)
	{
		(*nchars)++;
		n_longcopy /= 10;
	}
	retval = ft_calloc(*nchars, sizeof(char));
	if (!retval)
		return (NULL);
	if (*negative)
		*(retval) = '-';
	return (retval);
}

static long	ft_get_max_power(size_t ndigits, long long_n)
{
	long	power10;
	size_t	ichar;

	ichar = 0;
	power10 = 1;
	while (ichar < ndigits)
	{
		power10 *= 10;
		ichar++;
	}
	if (long_n / power10 == 0)
		power10 /= 10;
	return (power10);
}

char	*ft_itoa(int n)
{
	char	*retval[2];
	int		neg;
	size_t	nchars;
	long	n_long;
	long	power10;

	n_long = n;
	nchars = 0;
	neg = 0;
	retval[0] = ft_itoa_mem(&n_long, &neg, &nchars);
	retval[1] = retval[0];
	power10 = ft_get_max_power(nchars - neg - 1, n_long);
	if (neg)
		retval[1]++;
	while (power10 > 0)
	{
		*retval[1] = '0' + n_long / power10;
		n_long %= power10;
		power10 /= 10;
		retval[1]++;
	}
	*retval[1] = '\0';
	return (retval[0]);
}

int	main(int argc, char *argv[])
{
	char	*number_str;
	int		number_int;
	char	*result;
	int		debug;

	debug = 0;
	number_str = "-2147483648";
	number_str = "0";
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
