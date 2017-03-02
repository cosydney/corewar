/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:35:30 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/20 23:28:02 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static int	print_arg(char **str, va_list *lst, int fd)
{
	t_arg	arg;
	int		len;

	ft_bzero(&arg, sizeof(t_arg));
	arg.fd = fd;
	len = ft_printf_parse_arg(*str, &arg, lst);
	ft_printf_handler(&arg, lst);
	*str += len;
	return (arg.size);
}

int			ft_printf_core(int fd, const char *format, va_list *lst)
{
	char		*cursor;
	int			out;

	cursor = (char*)format;
	out = 0;
	while (*cursor)
	{
		if (*cursor == '%')
			out += print_arg(&cursor, lst, fd);
		else
		{
			ft_putchar_fd(*cursor++, fd);
			out++;
		}
	}
	return (out);
}
