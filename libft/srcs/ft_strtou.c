/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:44:54 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/02 19:26:48 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

unsigned int	ft_strtou(unsigned int *dest, const char *nbr)
{
	long long int	value;

	value = 0;
	while (*nbr == ' ' || *nbr == '\t' || *nbr == '\n' || *nbr == '\f' || \
			*nbr == '\r' || *nbr == '\v')
		nbr++;
	if (!ft_isdigit(*nbr))
		return (0);
	while (*nbr >= '0' && *nbr <= '9')
	{
		value *= 10;
		value += *nbr++ - '0';
		if (value > UINT_MAX)
			return (0);
	}
	*dest = (unsigned int)value;
	return ((*nbr == '\0') ? 1 : 0);
}
