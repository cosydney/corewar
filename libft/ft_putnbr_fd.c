/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:20:46 by abonneca          #+#    #+#             */
/*   Updated: 2016/11/05 18:08:14 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t			i;
	unsigned int	un;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -n;
	}
	else
		un = n;
	if (un / 10 != 0)
		ft_putnbr_fd(un / 10, fd);
	ft_putchar_fd(un % 10 + '0', fd);
}
