/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:50:15 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 16:08:34 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	t_uc	*from;
	t_uc	*to;

	from = (t_uc*)src;
	to = (t_uc*)dest;
	while (n--)
		*to++ = *from++;
	return (dest);
}
