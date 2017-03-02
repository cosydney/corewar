/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:51:52 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 18:07:22 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr(int n)
{
	size_t			i;
	unsigned int	un;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
		un = -n;
	}
	else
		un = n;
	if (un / 10 != 0)
		ft_putnbr(un / 10);
	ft_putchar(un % 10 + '0');
}
