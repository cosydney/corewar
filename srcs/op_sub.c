/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:52:52 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 14:05:55 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_sub(t_process *proc, t_vm *vm)
{
	unsigned int reg_a;
	unsigned int reg_b;
	unsigned int reg_res;

	(void)vm;
	reg_a = regtou(proc->act.params[0].value);
	reg_b = regtou(proc->act.params[1].value);
	reg_res = reg_a - reg_b;
	utoreg(reg_res, proc->act.params[2].value);
	proc->carry = 1;
}
