/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:53:29 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 16:06:08 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_out;

	len_dest = ft_strlen(dst);
	len_out = len_dest + ft_strlen(src);
	if (size < len_dest)
		return (len_out - (len_dest - size));
	if (size > 0)
	{
		while (*src && len_dest < (size - 1))
		{
			dst[len_dest++] = *src++;
		}
		dst[len_dest] = 0;
	}
	return (len_out);
}
