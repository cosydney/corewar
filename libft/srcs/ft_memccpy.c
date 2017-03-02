/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:49:46 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 16:12:06 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	t_uc	*from;
	t_uc	*to;

	from = (t_uc*)src;
	to = (t_uc*)dest;
	while (n--)
	{
		if ((*to++ = *from++) == (t_uc)c)
			return (to);
	}
	return (0);
}
