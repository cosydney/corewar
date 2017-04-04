/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:36:12 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:34:08 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_process *proc, t_vm *vm)
{
	unsigned int reg_a;
	unsigned int reg_b;
	unsigned int reg_res;
	unsigned int sum;

	(void)vm;
	if (!param_checker(proc))
		return ;
	reg_a = REGTOU(proc->act.params[0].value) - 1;
	reg_b = REGTOU(proc->act.params[1].value) - 1;
	reg_res = REGTOU(proc->act.params[2].value) - 1;
	if (reg_a >= REG_NUMBER || reg_b >= REG_NUMBER || reg_res >= REG_NUMBER)
		return ;
	sum = REGTOU(proc->registers[reg_a]) + REGTOU(proc->registers[reg_b]);
	utoreg(sum, proc->registers[reg_res]);
	proc->carry = sum ? 0 : 1;
}
