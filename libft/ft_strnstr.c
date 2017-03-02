/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:13:38 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 15:47:07 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (ft_strlen(little) == 0)
		return ((char *)(&big[0]));
	while (big[k] && i < len)
	{
		i = k;
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(&big[i - j]));
			i++;
			j++;
		}
		k++;
	}
	return (NULL);
}
