/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:11:29 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 15:47:22 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	if (ft_strlen(little) == 0)
		return ((char *)(&big[0]));
	while (big[k])
	{
		i = k;
		j = 0;
		while (big[i] == little[j])
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
