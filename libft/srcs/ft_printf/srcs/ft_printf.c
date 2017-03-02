/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:35:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/24 13:38:24 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	lst;

	va_start(lst, format);
	ret = ft_printf_core(1, format, &lst);
	va_end(lst);
	return (ret);
}
