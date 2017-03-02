/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:35:41 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 19:26:13 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	int		i;
	char	*cpy;

	i = 0;
	while (src[i])
		i++;
	if ((cpy = (char *)malloc(sizeof(char) * (i + 1))))
	{
		i = 0;
		while (src[i])
		{
			cpy[i] = src[i];
			i++;
		}
		cpy[i] = '\0';
	}
	else
		return (NULL);
	return (cpy);
}
