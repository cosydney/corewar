/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:51:10 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 19:19:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	t_uc	*from;
	t_uc	*to;

	from = (t_uc*)src;
	to = (t_uc*)dest;
	if (src + n >= dest && src < dest)
		while (n--)
			to[n] = from[n];
	else
		while (n--)
			*to++ = *from++;
	return (dest);
}
