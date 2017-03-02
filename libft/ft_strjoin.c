/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:52:07 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 15:43:01 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *res;

	if (!s1 || !s2)
		return (NULL);
	if (!(res = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	if (!ft_memcpy(res, s1, ft_strlen(s1)))
		return (NULL);
	if (!ft_memcpy(&res[ft_strlen(s1)], s2, ft_strlen(s2)))
		return (NULL);
	return (res);
}
