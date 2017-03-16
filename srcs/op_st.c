/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:56:00 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/16 13:28:41 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld_to_mem(unsigned int offset, t_byte reg[REG_SIZE], t_vm *vm)
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
	t_param			reg_param;
	t_byte			*reg_src;

	reg_src = proc->registers[regtou(proc->act.params[0].value) - 1];
	reg_param = proc->act.params[1];
	if (reg_param.t == T_REG)
		ft_memcpy(proc->registers[regtou(reg_param.value) - 1], reg_src, \
			REG_SIZE);
	else if (reg_param.t == T_IND)
	{
		ld_to_mem(((short)regtou(reg_param.value) % IDX_MOD) + \
		regtou(proc->act.pc), reg_src, vm);
	}
}
