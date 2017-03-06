/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:59:05 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/06 19:07:09 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_mem(byte *memory, size_t size)
{
	char counter;
	size_t i;
	size_t address;

	i = 0;
	counter = 0;
	address = 0;

	while (i < size)
	{
		if (counter == 0)
			ft_printf("%.7x:", address);
		ft_printf(" %.2hhx", memory[i]);
		++counter;
		++address;
		if (counter == 32)
		{
			counter = 0;
			ft_printf("\n");
		}
		i++;
	}
}

void	utoreg(unsigned int n, byte reg[REG_SIZE])
{
	int i;

	i = REG_SIZE;
	while (i--)
	{
		reg[i] = n & 0xff;
		n = n >> 8;
	}
}

unsigned int regtou(byte reg[REG_SIZE])
{
	int				i;
	unsigned int	res;

	res = 0;
	i = REG_SIZE;
	while (i--)
	{
		res += reg[i];
		res <<= 8;
	}
	return (res);
}

int		bytetou(byte *arr, unsigned int *n, size_t size)
{
	size_t	i;

	i = 0;
	if (size > sizeof(unsigned int))
		return (0);
	*n = 0;
	while (i < size)
	{
		*n = *n << 8;
		*n += arr[i++];
	}
	return (1);
}
