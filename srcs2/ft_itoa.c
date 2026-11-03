/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 08:34:57 by marisous          #+#    #+#             */
/*   Updated: 2026/11/03 15:34:55 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (negative)
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
	char	*retval;
	int		neg;
	size_t	nchars;
	long	n_long;
	long	power10;

	n_long = n;
	retval = ft_itoa_mem(&n_long, &neg, &nchars);
	power10 = ft_get_max_power(nchars - neg - 1, n_long);
	if (neg)
		retval++;
	while (power10 > 0)
	{
		*retval = '0' + n_long / power10;
		n_long %= power10;
		power10 /= 10;
		retval++;
	}
	retval -= (nchars - 1);
	return (retval);
}
