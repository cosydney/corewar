/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:07:27 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:34:49 by amarzial         ###   ########.fr       */
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
	unsigned int	idx;
	t_byte			*reg_dst;

	if (!param_checker(proc))
		return ;
	src_param = REGTOU(proc->act.params[0].value);
	if ((idx = REGTOU(proc->act.params[1].value) - 1) >= REG_NUMBER)
		return ;
	reg_dst = proc->registers[idx];
	if (proc->act.params[0].t == T_DIR)
		utoreg(src_param, reg_dst);
	else if (proc->act.params[0].t == T_IND)
		ld(REGTOU(proc->act.pc) + ((short)src_param), reg_dst, vm);
	proc->carry = (REGTOU(reg_dst)) ? 0 : 1;
}
