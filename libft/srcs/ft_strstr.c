/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:54:34 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 19:24:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *src, char *to_find)
{
	size_t	inner;
	int		found;

	if (*to_find == 0)
		return (src);
	while (*src)
	{
		found = 1;
		inner = 0;
		while (to_find[inner])
		{
			if (src[inner] != to_find[inner])
			{
				found = 0;
				break ;
			}
			inner++;
		}
		if (found)
			return (src);
		++src;
	}
	return (0);
}
