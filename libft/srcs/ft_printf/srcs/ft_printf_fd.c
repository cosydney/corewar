/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 22:35:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/01/24 13:38:01 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printf_fd(int fd, const char *format, ...)
{
	int		ret;
	va_list	lst;

	va_start(lst, format);
	ret = ft_printf_core(fd, format, &lst);
	va_end(lst);
	return (ret);
}
