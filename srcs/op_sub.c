/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:52:52 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 18:39:15 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_process *proc, t_vm *vm)
{
	unsigned int reg_a;
	unsigned int reg_b;
	unsigned int reg_res;
	unsigned int diff;

	(void)vm;
	if (!param_checker(proc))
		return ;
	reg_a = regtou(proc->act.params[0].value);
	reg_b = regtou(proc->act.params[1].value);
	reg_res = regtou(proc->act.params[2].value);
	if (reg_a > REG_NUMBER || reg_b > REG_NUMBER || reg_res > REG_NUMBER)
		return ;
	diff = regtou(proc->registers[reg_a]) - regtou(proc->registers[reg_b]);
	utoreg(diff, proc->registers[reg_res]);
	proc->carry = diff ? 0 : 1;
}
