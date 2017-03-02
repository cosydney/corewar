/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:50:07 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 16:47:15 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_uc	*mem1;
	t_uc	*mem2;

	mem1 = (t_uc*)s1;
	mem2 = (t_uc*)s2;
	while (n && *mem1 == *mem2)
	{
		++mem1;
		++mem2;
		--n;
	}
	if (n == 0)
		return (0);
	return (*mem1 - *mem2);
}
