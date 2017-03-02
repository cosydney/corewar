/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:34:06 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/04 10:18:01 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	k;

	k = 0;
	while (k < n)
	{
		if (((unsigned char*)src)[k] == (unsigned char)c)
		{
			((char*)dst)[k] = ((char*)src)[k];
			return (&dst[++k]);
		}
		((char*)dst)[k] = ((char*)src)[k];
		k++;
	}
	return (NULL);
}
