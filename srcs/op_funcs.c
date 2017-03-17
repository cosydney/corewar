/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:42:05 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/11 18:44:13 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

unsigned int	par_to_val(int par, size_t size, t_process *proc, t_vm *vm)
{
	t_param *p;

	p = &(proc->act.params[par]);
	if (p->t == T_REG)
		return (regtou(proc->registers[regtou(p->value)]));
	else if (p->t == T_DIR)
		return (regtou(p->value));
	else if (p->t == T_IND)
		return (memtou(vm->memory, (((short)regtou(p->value) % IDX_MOD) + \
		regtou(proc->pc)), size));
	return (0);
}

unsigned int	lpar_to_val(int par, size_t size, t_process *proc, t_vm *vm)
{
	t_param *p;

	p = &(proc->act.params[par]);
	if (p->t == T_REG)
		return (regtou(proc->registers[regtou(p->value)]));
	else if (p->t == T_DIR)
		return (regtou(p->value));
	else if (p->t == T_IND)
		return (memtou(vm->memory, ((short)regtou(p->value) + \
		regtou(proc->pc)), size));
	return (0);
}
