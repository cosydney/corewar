/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:25:02 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/08 19:50:41 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld(unsigned int offset, byte reg[REG_SIZE], t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg[i] = vm->memory[(offset + i) % MEM_SIZE];
		++i;
	}
}

static unsigned int		read_bytes(unsigned int offset, t_vm *vm)
{
	int	i;
	unsigned int sum;

	i = 0;
	sum = 0;
	while (i < REG_SIZE)
	{
		sum += vm->memory[(offset + i) % MEM_SIZE];
		++i;
	}
	return (sum);
}

void			op_ldi(t_process *proc, t_vm *vm)
{
	byte			*reg_first;
	byte			*reg_second;
	byte			*reg_dst;
	unsigned int	sum;

	reg_first = proc->act.params[0].value;
	reg_second = proc->act.params[1].value;
	reg_dst = proc->act.params[2].value;

	sum = regtou(reg_second) +\
	read_bytes(regtou(proc->pc) + (regtou(reg_first) % IDX_MOD), vm);
	proc->carry = (reg_dst) ? 0 : 1;
	ld(regtou(proc->pc) + (sum % IDX_MOD), reg_dst, vm);
}
