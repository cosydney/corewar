/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:28:41 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/04 17:58:49 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_process *proc, t_vm *vm)
{
	t_process *new_proc;

	new_proc = create_process(REGTOU(proc->act.pc) + \
				(short)REGTOU(proc->act.params[0].value), \
				proc->parent, vm);
	ft_memcpy(new_proc->registers, proc->registers, \
				(sizeof(t_byte) * REG_SIZE) * REG_NUMBER);
	if (new_proc->act.op)
		new_proc->cycle_count--;
	new_proc->live_count = proc->live_count;
	new_proc->carry = proc->carry;
}
