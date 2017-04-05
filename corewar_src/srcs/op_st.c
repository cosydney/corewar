/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:56:00 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:35:05 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_st(t_process *proc, t_vm *vm)
{
	t_param			reg_param;
	t_byte			*reg_src;
	unsigned int	idx;

	if (!param_checker(proc))
		return ;
	if ((idx = REGTOU(proc->act.params[0].value) - 1) >= REG_NUMBER)
		return ;
	reg_src = proc->registers[idx];
	reg_param = proc->act.params[1];
	if (reg_param.t == T_REG)
	{
		if ((idx = REGTOU(proc->act.params[1].value) - 1) >= REG_NUMBER)
			return ;
		ft_memcpy(proc->registers[idx], reg_src, REG_SIZE);
	}
	else if (reg_param.t == T_IND)
	{
		st_to_mem(((short)REGTOU(reg_param.value) % IDX_MOD) + \
		REGTOU(proc->act.pc), reg_src, proc, vm);
	}
}
