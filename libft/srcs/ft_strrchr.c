/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:54:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/26 15:31:41 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if (index == 0 && (char)c == 0)
		return (s);
	index++;
	while (index)
	{
		--index;
		if (s[index] == (char)c)
			return (s + index);
	}
	return (0);
}
