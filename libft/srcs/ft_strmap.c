/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:55:45 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 20:20:11 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*out;
	size_t	index;

	out = 0;
	if (s && (out = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		index = 0;
		while (s[index])
		{
			out[index] = f(s[index]);
			index++;
		}
		out[index] = '\0';
	}
	return (out);
}
