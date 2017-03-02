/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 15:15:43 by abonneca          #+#    #+#             */
/*   Updated: 2017/02/24 09:29:40 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] &&
			((unsigned char)(s1[i])) == ((unsigned char)(s2[i])))
		i++;
	return ((int)(((unsigned char)(s1[i])) - ((unsigned char)(s2[i]))));
}
