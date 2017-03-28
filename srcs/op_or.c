/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:33:29 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 18:40:02 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_or(t_process *proc, t_vm *vm)
{
	unsigned int a[2];
	unsigned int b[2];
	unsigned int idx;

	(void)vm;
	if (!param_checker(proc))
		return ;
	a[1] = REG_SIZE;
	b[1] = REG_SIZE;
	if (!par_to_val(0, a, proc, vm) || !par_to_val(1, b, proc,  vm))
		return ;
	if ((idx = regtou(proc->act.params[2].value) - 1) >= REG_NUMBER)
		return ;
	utoreg(a[0] | b[0], proc->registers[idx]);
	proc->carry = (a[0] | b[0]) ? 0 : 1;
}
