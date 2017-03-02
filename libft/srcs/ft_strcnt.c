/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 21:33:24 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/04 21:39:47 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcnt(const char *str, int c)
{
	size_t cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (*str)
	{
		if (*str++ == (unsigned char)c)
			cnt++;
	}
	return (cnt);
}
