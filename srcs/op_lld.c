/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:07:27 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/09 11:41:25 by amarzial         ###   ########.fr       */
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

void			op_lld(t_process *proc, t_vm *vm)
{
	unsigned int	src_param;
	t_byte			*reg_dst;

	src_param = regtou(proc->act.params[0].value);
	reg_dst = proc->registers[regtou(proc->act.params[1].value) - 1];
	if (proc->act.params[0].t == T_DIR)
		utoreg(src_param, reg_dst);
	else if (proc->act.params[0].t == T_IND)
		ld(regtou(proc->act.pc) + ((short)src_param), reg_dst, vm);
	proc->carry = (regtou(reg_dst)) ? 0 : 1;
}
