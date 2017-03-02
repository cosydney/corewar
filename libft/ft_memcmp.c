/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:34:06 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 17:29:41 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	k;

	k = 0;
	if (n == 0)
		return (0);
	while (k < n - 1 &&
			((unsigned char*)s2)[k] == (((unsigned char*)s1)[k]))
		k++;
	return ((int)((unsigned char*)s1)[k] - (((unsigned char*)s2)[k]));
}
