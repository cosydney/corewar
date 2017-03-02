/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 16:53:59 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/07 12:02:29 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**ft_splitstr(char const *s, char **res, char c, int word)
{
	size_t start;
	size_t len;
	size_t i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			start = i;
			while (s[i] != c && s[i])
			{
				len++;
				i++;
			}
			if (!(res[word] = ft_strsub(&s[start], 0, len)))
				return (NULL);
			word++;
		}
	}
	res[word] = 0;
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	words;

	res = NULL;
	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	if (!(res = (char **)malloc(sizeof(char *) * words + 1)))
		return (NULL);
	res = ft_splitstr(s, res, c, 0);
	return (res);
}
