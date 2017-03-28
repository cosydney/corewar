/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:59:03 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/28 20:13:46 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			op_sti(t_process *proc, t_vm *vm)
{
	unsigned int	first[2];
	unsigned int	second[2];
	unsigned int	idx;

	if (!param_checker(proc))
		return ;
	first[1] = REG_SIZE;
	second[1] = IND_SIZE;
	if (!par_to_val(1, first, proc, vm) || !par_to_val(2, second, proc, vm))
		return ;
	if ((idx = regtou(proc->act.params[0].value) - 1) >= REG_NUMBER)
		return ;
	st_to_mem(((first[0] + second[0]) % IDX_MOD) + regtou(proc->act.pc), \
		proc->registers[idx], proc, vm);
}
