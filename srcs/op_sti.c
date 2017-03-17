/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:59:03 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/09 18:35:22 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld_to_mem(unsigned int offset, t_byte reg[REG_SIZE], t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		vm->memory[(offset + i) % MEM_SIZE] = reg[i];
		++i;
	}
}

void			op_sti(t_process *proc, t_vm *vm)
{
	unsigned int	reg_param_first;
	unsigned int	reg_param_second;
	t_byte			*reg_src;

	reg_src = proc->act.params[0].value;
	reg_param_first = par_to_val(1, IND_SIZE, proc, vm);
	reg_param_second = par_to_val(2, IND_SIZE, proc, vm);
	ld_to_mem((reg_param_first + reg_param_second) % IDX_MOD, reg_src, vm);
}
