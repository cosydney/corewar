/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:31:46 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 15:44:55 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	res = NULL;
	if (s)
		if ((res = ft_strnew(ft_strlen(s))))
		{
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			return (res);
		}
	return (NULL);
}
