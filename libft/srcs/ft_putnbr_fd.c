/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 21:02:38 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/07 14:09:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(t_putnbr n, int fd)
{
	char	digits[20];
	int		sign;
	int		count;

	sign = 1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	if (n < 0)
	{
		sign = -1;
		ft_putchar_fd('-', fd);
	}
	count = 0;
	while (n != 0)
	{
		digits[count] = sign * (n % 10) + '0';
		n /= 10;
		count += 1;
	}
	while (count)
		ft_putchar_fd(digits[count-- - 1], fd);
}
