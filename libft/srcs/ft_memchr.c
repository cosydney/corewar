/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:50:00 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 18:50:23 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_uc	*cur;

	cur = (t_uc*)s;
	while (n--)
	{
		if (*cur == (t_uc)c)
			return (cur);
		++cur;
	}
	return (0);
}
