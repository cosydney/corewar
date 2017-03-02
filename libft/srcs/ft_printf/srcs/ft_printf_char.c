/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 17:27:12 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 22:17:30 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		padding(char out, t_arg *arg, int len)
{
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set && arg->precision > 0)
		len = ft_min(len, arg->precision);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			ft_putchar_fd(out, arg->fd);
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len, arg->fd);
			ft_putchar_fd(out, arg->fd);
		}
	}
	else
		ft_putchar_fd(out, arg->fd);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_char(t_arg *arg, va_list *lst)
{
	char	c;
	size_t	len;

	if (arg->conversion == '%')
		c = '%';
	else
	{
		if (arg->length_mod == l)
			return (ft_printf_wchar(arg, lst));
		c = (char)va_arg(*lst, int);
	}
	len = 1;
	padding(c, arg, len);
	return (len);
}
