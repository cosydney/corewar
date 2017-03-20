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
	unsigned int	first[2];
	unsigned int	second[2];
	t_byte			*reg_src;

	if (!param_checker(proc))
		return ;
	reg_src = proc->act.params[0].value;
	first[1] = IND_SIZE;
	second[1] = IND_SIZE;
	if (!par_to_val(1, first, proc, vm) || !par_to_val(2, second, proc, vm))
		return ;
	ld_to_mem(((first[0] + second[0]) % IDX_MOD) + regtou(proc->act.pc), \
		reg_src, vm);
}
