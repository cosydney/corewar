/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:59:05 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/02 22:59:25 by amarzial         ###   ########.fr       */
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
