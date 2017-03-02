/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:24:42 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 20:20:24 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	index;
	char	*out;

	out = 0;
	if (s && (out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		index = 0;
		while (s[index])
		{
			out[index] = f(index, s[index]);
			index++;
		}
		out[index] = '\0';
	}
	return (out);
}
