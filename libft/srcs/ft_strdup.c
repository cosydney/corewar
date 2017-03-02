/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:53:01 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/12 16:57:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	cur;

	if ((out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		cur = 0;
		while (s[cur])
		{
			out[cur] = s[cur];
			++cur;
		}
		out[cur] = '\0';
	}
	return (out);
}
