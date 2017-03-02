/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:43:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/07 14:09:02 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(t_putnbr n)
{
	char	digits[20];
	int		sign;
	int		count;

	sign = 1;
	if (n == 0)
		ft_putchar('0');
	if (n < 0)
	{
		sign = -1;
		ft_putchar('-');
	}
	count = 0;
	while (n != 0)
	{
		digits[count] = sign * (n % 10) + '0';
		n /= 10;
		count += 1;
	}
	while (count)
		ft_putchar(digits[count-- - 1]);
}
