/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:56:00 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 18:39:52 by abonneca         ###   ########.fr       */
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

void			op_st(t_process *proc, t_vm *vm)
{
	byte			*reg_param;
	byte			*reg_dst;

	reg_param = proc->act.params[0].value;
	reg_dst = proc->act.params[1].value;
	proc->carry = (reg_dst) ? 0 : 1;
	if (proc->act.params[1].t == T_DIR)
		ld_to_mem(regtou(proc->pc) + (regtou(reg_param) % IDX_MOD), reg_dst, vm);
	else if (proc->act.params[1].t == T_IND)
		ld_to_mem(regtou(reg_param), reg_dst, vm);
}
