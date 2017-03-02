/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 19:53:17 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/18 20:12:52 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ndigits(int n)
{
	int	ret;

	if (n == 0)
		return (1);
	ret = 0;
	if (n <= 0)
		ret++;
	while (n)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

char		*ft_itoa(int n)
{
	char	*out;
	int		index;
	int		size;

	size = ndigits(n);
	if ((out = ft_strnew(size)))
	{
		index = 0;
		if (n == 0)
			out[0] = '0';
		else
		{
			if (n < 0)
				out[0] = '-';
			while (n)
			{
				out[size - index++ - 1] = ft_abs((n % 10)) + '0';
				n /= 10;
			}
		}
	}
	return (out);
}
