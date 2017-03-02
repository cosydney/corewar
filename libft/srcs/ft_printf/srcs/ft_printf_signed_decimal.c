/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_signed_decimal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:21:43 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 22:20:15 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static intmax_t	fetch_int(t_arg *arg, va_list *lst)
{
	intmax_t	var;

	var = va_arg(*lst, intmax_t);
	if (arg->conversion == 'D')
		arg->length_mod = l;
	if (arg->length_mod == hh)
		return ((char)var);
	else if (arg->length_mod == h)
		return ((short int)var);
	else if (arg->length_mod == l)
		return ((long int)var);
	else if (arg->length_mod == ll)
		return ((long long int)var);
	else if (arg->length_mod == j)
		return ((intmax_t)var);
	else if (arg->length_mod == z)
		return ((ssize_t)var);
	return ((int)var);
}

static void		padding(char *out, int len, t_arg *arg)
{
	int	offset;

	offset = 0;
	if (arg->size > len)
	{
		if (arg->flag_left)
		{
			ft_memmove(out, out + (arg->size - len), len);
			ft_memset(out + len, ' ', arg->size - len);
		}
		else if (arg->flag_zero)
		{
			if (!(ft_isdigit(out[arg->size - len])))
				out[offset++] = out[arg->size - len];
			ft_memset(out + offset, '0', arg->size - len);
		}
		else
			ft_memset(out, ' ', arg->size - len);
	}
}

int				ft_printf_signed_decimal(t_arg *arg, va_list *lst)
{
	intmax_t	num;
	char		*out;
	int			len;

	num = fetch_int(arg, lst);
	len = ft_max(idigits(num, 10), arg->precision) \
			+ ((num < 0 || arg->flag_sign || arg->flag_space) ? 1 : 0);
	if (num == 0 && arg->prec_set && arg->precision == 0)
		len--;
	arg->size = ft_max(arg->field_width, len);
	if (!(out = ft_strnew(arg->size)))
		return (0);
	if (arg->flag_left || arg->prec_set)
		arg->flag_zero = 0;
	ft_printf_signedtostr(out + (arg->size - len), num, arg);
	padding(out, len, arg);
	ft_putstr_fd(out, arg->fd);
	len = ft_strlen(out);
	free(out);
	return (len);
}
