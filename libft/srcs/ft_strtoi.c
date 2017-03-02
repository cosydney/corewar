/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:44:54 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/08 17:27:58 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

int		ft_strtoi(int *dest, const char *nbr)
{
	long long int	value;
	int				sign;

	while (*nbr == ' ' || *nbr == '\t' || *nbr == '\n' || *nbr == '\f' || \
			*nbr == '\r' || *nbr == '\v')
		nbr++;
	sign = 1;
	if (*nbr == '-' || *nbr == '+')
	{
		sign = *nbr == '-' ? -1 : 1;
		nbr++;
	}
	value = 0;
	if (!ft_isdigit(*nbr))
		return (0);
	while (*nbr >= '0' && *nbr <= '9')
	{
		value *= 10;
		value += *nbr++ - '0';
		if (value > INT_MAX || value < INT_MIN)
			return (0);
	}
	*dest = value * sign;
	return (1);
}
