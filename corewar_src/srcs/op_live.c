/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:56:00 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/07 19:21:21 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include <limits.h>

void	op_live(t_process *proc, t_vm *vm)
{
	unsigned int	id;
	t_champion		*champ;

	(void)vm;
	id = UINT_MAX - REGTOU(proc->act.params[0].value) + 1;
	if ((champ = id_to_champion(vm->players, id)))
	{
		vm->last_live_id = id;
		champ->live_calls++;
	}
	proc->live_count++;
	vm->live_count++;
	vm->live_total++;
}
