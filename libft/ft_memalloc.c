/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:58:30 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 18:39:47 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memalloc;

	if (!(memalloc = (void *)(malloc(sizeof(void) * size))))
		return (NULL);
	return (ft_memset(memalloc, 0, size));
}
