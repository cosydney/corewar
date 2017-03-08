/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:25:02 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/08 18:41:25 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld(unsigned int offset, byte reg[REG_SIZE], t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg[i] = vm->memory[(offset + i) % MEM_SIZE];
		++i;
	}
}

void			op_ld(t_process *proc, t_vm *vm)
{
	byte			*reg_param;
	byte			*reg_dst;

	reg_param = proc->act.params[0].value;
	reg_dst = proc->act.params[1].value;
	proc->carry = (reg_dst) ? 0 : 1;
	if (proc->act.params[0].t == T_DIR)
		ld(regtou(proc->pc) + (regtou(reg_param) % IDX_MOD), reg_dst, vm);
	else if (proc->act.params[0].t == T_IND)
		ld(regtou(reg_param), reg_dst, vm);
}
