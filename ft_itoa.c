/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 08:34:57 by marisous          #+#    #+#             */
/*   Updated: 2026/11/07 15:00:38 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates buffer and calculates metadata (digits, sign) for itoa.
 *
 * @param n_long Pointer to long value of number (made positive if negative).
 * @param negative Pointer to int set to 1 if n was negative, 0 otherwise.
 * @param nchars Pointer to size_t to receive total required buffer size.
 * @return Allocated string buffer with '-' set if negative, or NULL on failure.
 */
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

/**
 * @brief Computes highest base-10 power corresponding to most significant digit.
 *
 * @param ndigits Number of digits in the integer.
 * @param long_n Positive number value.
 * @return The base 10 divisor matching the most significant digit.
 */
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
	if (retval == NULL)
		return (NULL);
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
