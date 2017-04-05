/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjump.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:42:40 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:35:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_zjump(t_process *proc, t_vm *vm)
{
	(void)vm;
	if (proc->carry)
		utoreg((REGTOU(proc->act.pc) + \
		((short)REGTOU(proc->act.params[0].value) % IDX_MOD)) % MEM_SIZE, \
			proc->pc);
}
