/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:56:00 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/09 18:17:27 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_process *proc, t_vm *vm)
{
	unsigned int id;

	(void)vm;
	id = regtou(proc->act.params[0].value);
	vm->last_live_id = id;
	vm->live_count++;
}
