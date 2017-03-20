/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:56:00 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/10 13:44:33 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_process *proc, t_vm *vm)
{
	unsigned int id;

	(void)vm;
	id = regtou(proc->act.params[0].value);
	if (id_to_champion(vm->players, id))
		vm->last_live_id = id;
	proc->live_count++;
	vm->live_count++;
}
