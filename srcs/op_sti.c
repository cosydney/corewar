/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:59:03 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/09 18:35:22 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld_to_mem(unsigned int offset, byte reg[REG_SIZE], t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		vm->memory[(offset + i) % MEM_SIZE] = reg[i];
		++i;
	}
}

void			op_sti(t_process *proc, t_vm *vm)
{
	byte			*reg_param_first;
	byte			*reg_param_second;
	byte			*reg_src;

	reg_src = proc->act.params[0].value;
	reg_param_first = proc->act.params[1].value;
	reg_param_second = proc->act.params[2].value;
	proc->carry = (reg_src) ? 0 : 1;
	ld_to_mem(regtou(reg_param_first) + regtou(reg_param_second), reg_src, vm);
}
