/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:48:35 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/06 10:48:38 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*cleaner;
	void	*ret;

	if ((ret = malloc(sizeof(char) * size)))
	{
		cleaner = (char*)ret;
		while (size)
		{
			cleaner[size - 1] = 0;
			size--;
		}
	}
	return (ret);
}
