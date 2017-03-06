/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 15:56:00 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/06 18:05:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_live(t_process *proc, t_vm *vm)
{
	unsigned int id;

	bytetou(proc->act.four, &id, 4);
	//callalive(id, vm);
	vm->live_count++;
}
