/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:53:17 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/17 16:18:37 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

void		ft_printf_unsignedtostr_base(char *out, uintmax_t n, \
t_arg *arg, char *base)
{
	int		index;
	int		size;
	int		len;
	int		b;

	b = ft_strlen(base);
	len = udigits(n, b);
	size = ft_max(len, arg->precision);
	index = 0;
	while (index < size - len)
		out[index++] = '0';
	if (n == 0 && !(arg->prec_set && arg->precision == 0))
		out[index] = '0';
	else
	{
		while (n)
		{
			out[size-- - 1] = base[ft_abs((n % b))];
			n /= b;
		}
	}
}
