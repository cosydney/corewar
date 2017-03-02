/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:00:54 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 15:48:04 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	if (!(res = ft_strnew(len)) || !s)
		return (NULL);
	while (len > 0)
	{
		res[i] = s[start];
		start++;
		i++;
		len--;
	}
	res[i] = 0;
	return (res);
}
