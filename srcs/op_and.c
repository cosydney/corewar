/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:17:53 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:34:22 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_process *proc, t_vm *vm)
{
	unsigned int a[2];
	unsigned int b[2];
	unsigned int idx;

	(void)vm;
	if (!param_checker(proc))
		return ;
	a[1] = REG_SIZE;
	b[1] = REG_SIZE;
	if (!par_to_val(0, a, proc, vm) || !par_to_val(1, b, proc, vm))
		return ;
	if ((idx = REGTOU(proc->act.params[2].value) - 1) >= REG_NUMBER)
		return ;
	utoreg(a[0] & b[0], proc->registers[idx]);
	proc->carry = (a[0] & b[0]) ? 0 : 1;
}
