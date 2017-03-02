/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:19:56 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 17:31:36 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (s1[i] && s2[i] && i < n &&
			((unsigned char)(s1[i])) == ((unsigned char)(s2[i])))
		i++;
	if (i == n)
		return (0);
	return ((int)(((unsigned char)(s1[i])) - ((unsigned char)(s2[i]))));
}
