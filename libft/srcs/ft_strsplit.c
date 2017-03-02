/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:49:01 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 20:19:13 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *str, char c)
{
	size_t count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str != c && *str)
				str++;
			continue ;
		}
		while (*str == c)
			str++;
	}
	return (count);
}

static size_t	word_len(char const *str, char c)
{
	size_t	size;

	size = 0;
	while (str[size] != c && str[size] != '\0')
		size++;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	cur;
	size_t	words;
	char	**tab;

	cur = 0;
	if (!s)
		return (0);
	words = count_words(s, c);
	if ((tab = (char**)ft_memalloc(sizeof(char*) * (words + 1))))
	{
		while (*s)
		{
			if (*s != c)
			{
				words = word_len(s, c);
				if (!(tab[cur++] = ft_strsub(s, 0, words)))
					return (0);
				s += words;
			}
			else
				s++;
		}
	}
	return (tab);
}
