/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:12:47 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/06 14:48:29 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	i = 0;
	res = NULL;
	if (s)
		if ((res = ft_strnew(ft_strlen(s))))
		{
			while (s[i])
			{
				res[i] = f(s[i]);
				i++;
			}
			return (res);
		}
	return (NULL);
}
