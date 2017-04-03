/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:59:05 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/16 13:29:58 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void				ft_print_mem(t_byte *memory, size_t size)
{
	char	counter;
	size_t	i;
	size_t	address;

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

void				utoreg(unsigned int n, t_byte reg[REG_SIZE])
{
	int i;

	i = REG_SIZE;
	while (i--)
	{
		reg[i] = n & 0xff;
		n = n >> 8;
	}
}
/*
unsigned int		regtou(t_byte reg[REG_SIZE])
{
	unsigned int	res;

	res = reg[3] + (reg[2] << 8) + (reg[1] << 16) + (reg[0] << 24);
	return (res);
}*/

unsigned int		memtou(t_byte *mem, unsigned int offset, size_t size)
{
	unsigned int	i;
	unsigned int	res;

	res = 0;
	i = 0;
	while (i < size)
	{
		res <<= 8;
		res += mem[(offset + i++) % MEM_SIZE];
	}
	return (res);
}
