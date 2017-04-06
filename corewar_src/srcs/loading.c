/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 20:12:26 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/28 20:28:33 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		load_to_memory(int fd, int offset, t_vm *vm, unsigned int prog_size)
{
	char test;

	if (prog_size > CHAMP_MAX_SIZE)
		return (0);
	if (read(fd, vm->memory + offset, prog_size) != prog_size)
		return (0);
	if (read(fd, &test, 1) != 0)
		return (0);
	return (1);
}
