/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:44:54 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/27 23:25:04 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

intmax_t	ft_atoi2(const char *nbr)
{
	uintmax_t		value;
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
	while (*nbr >= '0' && *nbr <= '9')
	{
		value *= 10;
		value += *nbr++ - '0';
	}
	return (value * sign);
}
