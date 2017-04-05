/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:59:03 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:35:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_sti(t_process *proc, t_vm *vm)
{
	unsigned int	first[2];
	unsigned int	second[2];
	unsigned int	idx;
	int				offset;

	if (!param_checker(proc))
		return ;
	first[1] = REG_SIZE;
	second[1] = IND_SIZE;
	if (!par_to_val(1, first, proc, vm) || !par_to_val(2, second, proc, vm))
		return ;
	if ((idx = REGTOU(proc->act.params[0].value) - 1) >= REG_NUMBER)
		return ;
	offset = 0;
	offset += (\
			proc->act.params[1].t == T_DIR) ? (short)first[0] : (int)first[0];
	offset += (\
			proc->act.params[2].t == T_DIR) ? (short)second[0] : (int)second[0];
	st_to_mem(((offset) % IDX_MOD) + REGTOU(proc->act.pc), \
		proc->registers[idx], proc, vm);
}
