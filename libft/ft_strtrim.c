/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:06:17 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 15:48:35 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*res;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start == ft_strlen(s))
	{
		if (!(res = ft_strnew(0)))
			return (NULL);
		return (res);
	}
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	if (!(res = ft_strsub(s, start, end - start + 1)))
		return (NULL);
	return (res);
}
