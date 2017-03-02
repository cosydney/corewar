/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:53:59 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 17:14:33 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*tmp;

	tmp = dest;
	while (n && *src)
	{
		*dest = *src;
		++dest;
		++src;
		--n;
	}
	while (n)
	{
		*dest = '\0';
		++dest;
		--n;
	}
	return (tmp);
}
