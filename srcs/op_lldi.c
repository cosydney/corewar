/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:28:17 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/09 18:36:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld(unsigned int offset, t_byte reg[REG_SIZE], t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg[i] = vm->memory[(offset + i) % MEM_SIZE];
		++i;
	}
}

void			op_lldi(t_process *proc, t_vm *vm)
{
	unsigned int	first;
	unsigned int	second;
	t_byte			*reg_dst;

	first = lpar_to_val(0, IND_SIZE, proc, vm);
	second = lpar_to_val(1, IND_SIZE, proc, vm);
	reg_dst = proc->registers[regtou(proc->act.params[2].value) - 1];
	ld(regtou(proc->pc) + (first + second), \
		reg_dst, vm);
	proc->carry = (regtou(reg_dst)) ? 0 : 1;
}
