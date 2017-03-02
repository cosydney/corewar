/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:54:04 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 17:06:42 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	index;

	if ((ret = (char*)malloc(sizeof(char) * (size + 1))))
	{
		index = 0;
		while (index < (size + 1))
			ret[index++] = '\0';
	}
	return (ret);
}
