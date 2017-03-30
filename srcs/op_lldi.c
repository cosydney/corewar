/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lldi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:28:17 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/28 14:42:44 by amarzial         ###   ########.fr       */
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
	unsigned int	first[2];
	unsigned int	second[2];
	unsigned int	idx;
	t_byte			*reg_dst;

	if (!param_checker(proc))
		return ;
	first[1] = IDX_MOD;
	second[1] = IDX_MOD;
	if (!par_to_val(0, first, proc, vm) || !par_to_val(1, second, proc, vm))
		return ;
	if ((idx = regtou(proc->act.params[2].value) - 1) >= REG_NUMBER)
		return ;
	reg_dst = proc->registers[idx];
	ld(regtou(proc->act.pc) + ((first[0] + second[0])), reg_dst, vm);
	proc->carry = (regtou(reg_dst)) ? 0 : 1;
}
