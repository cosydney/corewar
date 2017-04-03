/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:28:41 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/28 14:43:13 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_lfork(t_process *proc, t_vm *vm)
{
	t_process *new_proc;

	new_proc = create_process(regtou(proc->act.pc) + \
				(short)regtou(proc->act.params[0].value), \
				proc->parent, vm);
	ft_memcpy(new_proc->registers, proc->registers, \
				(sizeof(t_byte) * REG_SIZE) * REG_NUMBER);
	if (new_proc->act.op)
		new_proc->cycle_count--;
	new_proc->carry = proc->carry;
}
