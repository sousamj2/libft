/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 12:07:21 by marisous          #+#    #+#             */
/*   Updated: 2026/10/29 18:42:37 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_remove_space(char *nptr)
{
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	return (nptr);
}

static char	*ft_handle_sign_and_zeros(char *num, int *negative)
{
	*negative = 0;
	if (num[0] == '-')
	{
		*negative = 1;
		num++;
	}
	else if (num[0] == '+')
		num++;
	while (*num == '0')
		num++;
	return (num);
}

static int	ft_valid_num(char *num)
{
	int	ndigits;
	int	negative;

	ndigits = 0;
	num = ft_handle_sign_and_zeros(num, &negative);
	while (ft_isdigit(*num))
	{
		num++;
		ndigits++;
	}
	if (!negative && (ndigits > 19 || (ndigits == 19
				&& ft_strncmp(num - ndigits, "9223372036854775807", 19) > 0)))
		return (-1);
	if (negative && (ndigits > 19 || (ndigits == 19
				&& ft_strncmp(num - ndigits, "9223372036854775808", 19) > 0)))
		return (0);
	return (1);
}

int	ft_atoi(const char *nptr)
{
	char		*num;
	int			signal;
	long long	result;

	num = ft_remove_space((char *)nptr);
	signal = 1;
	result = ft_valid_num(num);
	if (result != 1)
		return (result);
	result = 0;
	if (num[0] == '-')
	{
		signal = -1;
		num++;
	}
	if (num[0] == '+')
		num++;
	while (ft_isdigit(*num))
	{
		result *= 10;
		result += *num - '0';
		num++;
	}
	return ((int) signal * result);
}

/* int main(int argc, char *argv[]) */
/* { */
/*     if (argc < 2) */
/*     { */
/* 		printf("Not enough args to execute %s.\n",argv[0]); */
/* 		return (-1); */
/* 	} */
/* 	printf("   ATOI [%s] -> [%d]\n", argv[1], atoi(argv[1])); */
/* 	printf("FT_ATOI [%s] -> [%d]\n", argv[1], ft_atoi(argv[1])); */
/* 	printf("Long:  %ld - %ld\n", LONG_MIN, LONG_MAX); */

/*     return (0); */
/* } */
