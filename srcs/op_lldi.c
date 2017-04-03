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
	int				offset;
	t_byte			*reg_dst;

	if (!param_checker(proc))
		return ;
	first[1] = REG_SIZE;
	second[1] = IND_SIZE;
	if (!par_to_val(0, first, proc, vm) || !par_to_val(1, second, proc, vm))
		return ;
	if ((idx = regtou(proc->act.params[2].value) - 1) >= REG_NUMBER)
		return ;
	reg_dst = proc->registers[idx];
	offset = 0;
	offset += (proc->act.params[0].t == T_DIR) ? (short)first[0] : (int)first[0];
	offset += (proc->act.params[1].t == T_DIR) ? (short)second[0] : (int)second[0];
	ld(regtou(proc->act.pc) + ((offset)), reg_dst, vm);
	proc->carry = (regtou(reg_dst)) ? 0 : 1;
}
