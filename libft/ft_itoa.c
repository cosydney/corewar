/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 19:09:26 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/06 15:25:16 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char		*ft_case_z(int c)
{
	char			*res;

	c = 0;
	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = '0';
	return (res);
}

static	int			ft_get_size(int n)
{
	int				size;

	size = 0;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static	void		ft_fill_str(char *res, unsigned int un, int size)
{
	while (--size >= 0)
	{
		res[size] = un % 10 + '0';
		un /= 10;
	}
}

char				*ft_itoa(int n)
{
	char			*res;
	int				size;
	int				neg;
	unsigned int	un;

	size = 0;
	neg = 0;
	if (n == 0)
		return (ft_case_z(0));
	if (n < 0)
	{
		size++;
		neg = 1;
		un = -n;
	}
	else
		un = n;
	size += ft_get_size(n);
	if (!(res = ft_strnew(size)))
		return (NULL);
	ft_fill_str(res, un, size);
	if (neg)
		res[0] = '-';
	return (res);
}
