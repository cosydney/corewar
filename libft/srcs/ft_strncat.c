/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:53:43 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 19:33:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	cur;
	char	*tmp;

	cur = 0;
	tmp = dest + ft_strlen(dest);
	while (*src && cur < n)
	{
		tmp[cur] = *src;
		++cur;
		++src;
	}
	tmp[cur] = '\0';
	return (dest);
}
