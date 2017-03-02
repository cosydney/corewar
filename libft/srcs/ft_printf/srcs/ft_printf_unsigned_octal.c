/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_base.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 21:49:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 22:22:01 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
#include "ft_printf_internal.h"

static uintmax_t	fetch_int(t_arg *arg, va_list *lst)
{
	uintmax_t	var;

	var = va_arg(*lst, uintmax_t);
	if (arg->conversion == 'O' || arg->conversion == 'U')
		arg->length_mod = l;
	if (arg->length_mod == hh)
		return ((unsigned char)var);
	else if (arg->length_mod == h)
		return ((unsigned short int)var);
	else if (arg->length_mod == l)
		return ((unsigned long int)var);
	else if (arg->length_mod == ll)
		return ((unsigned long long int)var);
	else if (arg->length_mod == j)
		return ((uintmax_t)var);
	else if (arg->length_mod == z)
		return ((size_t)var);
	return ((unsigned int)var);
}

static char			*getprefix(t_arg *arg)
{
	if (arg->flag_alt)
	{
		if (arg->conversion == 'o' || arg->conversion == 'O')
			return ("0");
	}
	return ("");
}

static void			padding(char *out, int len, t_arg *arg, uintmax_t num)
{
	int	offset;

	offset = ft_strlen(getprefix(arg));
	if (!num)
		offset = 0;
	if (arg->flag_alt && len)
	{
		ft_memcpy(out + (arg->size - len - offset), getprefix(arg), offset);
		len += offset;
	}
	if (arg->size > len)
	{
		if (arg->flag_left)
		{
			ft_memmove(out, out + (arg->size - len), len);
			ft_memset(out + len, ' ', arg->size - len);
		}
		else if (arg->flag_zero)
		{
			ft_memmove(out, out + (arg->size - len), offset);
			ft_memset(out + offset, '0', arg->size - len);
		}
		else
			ft_memset(out, ' ', arg->size - len);
	}
}

static int			octallen(int digs, int prec, t_arg *arg)
{
	if (digs + 1 <= prec)
		arg->flag_alt = 0;
	return (ft_max(digs, prec));
}

int					ft_printf_unsigned_octal(t_arg *arg, va_list *lst)
{
	uintmax_t	num;
	char		*out;
	int			len;
	char		*base;

	base = "01234567";
	num = fetch_int(arg, lst);
	if (arg->flag_left)
		arg->flag_zero = 0;
	len = octallen(udigits(num, 8), arg->precision, arg);
	if ((arg->conversion == 'o' || arg->conversion == 'O') && \
	arg->prec_set && arg->precision == 0)
		arg->precision = arg->flag_alt;
	if (num == 0 && arg->prec_set && arg->precision == 0)
		len--;
	arg->size = ft_max(arg->field_width, len + \
	((num) ? ft_strlen(getprefix(arg)) : 0));
	if (!(out = ft_strnew(arg->size)))
		return (0);
	ft_printf_unsignedtostr_base(out + (arg->size - len), num, arg, base);
	padding(out, len, arg, num);
	len = ft_strlen(out);
	ft_putstr_fd(out, arg->fd);
	free(out);
	return (len);
}
