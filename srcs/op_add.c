/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:36:12 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/07 16:47:01 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_add(t_process *proc, t_vm *vm)
{
	unsigned int reg_a;
	unsigned int reg_b;
	unsigned int reg_res;

	reg_a = regtou(proc->act.params[0]);
	reg_b = regtou(proc->act.params[1]);
	reg_res = reg_a + reg_b;
	utoreg(reg_res, proc->act.params[2])
	proc->carry = 1;
}
