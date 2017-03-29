/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 18:42:05 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/29 20:05:27 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				par_to_val(int par, unsigned int *vars, t_process *proc, \
t_vm *vm)
{
	t_param			*p;
	unsigned int	tmp;

	p = &(proc->act.params[par]);
	if (p->t == T_REG)
	{
		tmp = regtou(p->value);
		if (tmp > REG_NUMBER || !tmp)
			return (0);
		vars[0] = (regtou(proc->registers[tmp - 1]));
	}
	else if (p->t == T_DIR)
		vars[0] = (regtou(p->value));
	else if (p->t == T_IND)
	{
		if (vars[1] != IND_SIZE)
			vars[0] = (memtou(vm->memory, ((regtou(p->value) % IDX_MOD) + \
							regtou(proc->act.pc)), vars[1]));
		else
			vars[0] = (memtou(vm->memory, (((short)regtou(p->value) % IDX_MOD) \
							+ regtou(proc->act.pc)), vars[1]));
	}
	return (1);
}

int				lpar_to_val(int par, unsigned int *vars, t_process *proc, \
t_vm *vm)
{
	t_param			*p;
	unsigned int	tmp;

	p = &(proc->act.params[par]);
	if (p->t == T_REG)
	{
		tmp = regtou(p->value);
		if (tmp > REG_NUMBER || !tmp)
			return (0);
		vars[0] = (regtou(proc->registers[tmp - 1]));
	}
	else if (p->t == T_DIR)
		vars[0] = (regtou(p->value));
	else if (p->t == T_IND)
	{
		if (vars[1] != IND_SIZE)
			vars[0] = (memtou(vm->memory, ((short)regtou(p->value) + \
				regtou(proc->pc)), vars[1]));
		else
			vars[0] = (memtou(vm->memory, ((short)regtou(p->value) + \
				regtou(proc->pc)), vars[1]));
	}
	return (1);
}

int				param_checker(t_process *proc)
{
	int i;

	i = 0;
	while (i < proc->act.op->arg_c)
	{
		if (!(proc->act.params[i].t & proc->act.op->ar[i]))
			return (0);
		i++;
	}
	return (1);
}

void			st_to_mem(unsigned int offset, t_byte reg[REG_SIZE], \
		t_process *proc, t_vm *vm)
{
	int	i;
	int	idx;

	i = 0;
	while (i < REG_SIZE)
	{
		idx = (offset + i) % MEM_SIZE;
		vm->memory[idx] = reg[i];
		if (vm->opt.gui)
		{
			vm->gui.fresh[0][idx] += UI_TIME_NEW;
		}
		++i;
	}
	if (vm->opt.gui)
		gui_writemem(offset % MEM_SIZE, proc->parent->id, vm);
}
