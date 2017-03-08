/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:25:02 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/08 18:34:52 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
/*
static void		ld_ind(unsigned int offset, byte *reg, t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
		reg[i++] = vm->memory[(offset + i) % MEM_SIZE];
}

void			op_ldi(t_process *proc, t_vm *vm)
{
	unsigned int	reg_n;
	byte			*value;
	unsigned int	ind;

	reg_n = regtou(proc->act.params[0].value) - 1;
	value = proc->act.params[1].value;
	ind = regtou(value);
	proc->carry = (ind) ? 0 : 1;
	if (proc.act->params[1].t == T_DIR)
		ft_memcpy(proc->registers + reg_n, value, REG_SIZE);
	else if (proc.act->params[1].t == T_DIR)
		ld_ind(regtou(proc->pc) + (ind % IDX_MOD), proc->registers + reg_n, vm);
}*/
