/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:17:53 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/11 18:59:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_and(t_process *proc, t_vm *vm)
{
	unsigned int i;

	(void)vm;
	i = par_to_val(0, REG_SIZE, proc, vm) & par_to_val(1, REG_SIZE, proc,  vm);
	utoreg(i, proc->registers[regtou(proc->act.params[2].value) - 1]);
	proc->carry = i ? 0 : 1;
}
