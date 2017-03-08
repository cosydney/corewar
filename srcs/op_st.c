/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:56:00 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 15:45:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld_reg(unsigned int offset, byte *reg, t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
		reg[i++] = vm->memory[(offset + i) % MEM_SIZE];
}

void			op_st(t_process *proc, t_vm *vm)
{
	unsigned int	reg_n;
	byte			*value;
	unsigned int	ind;

	reg_n = regtou(proc->act.params[1].value) - 1;
	value = proc->act.params[0].value;
	ind = regtou(value);
	proc->carry = (ind) ? 0 : 1;
	if (proc->act.params[0].t == T_DIR)
		ft_memcpy(proc->registers + reg_n, value, REG_SIZE);
	else if (proc->act.params[0].t == T_REG)
		ld_reg(regtou(proc->pc) + (ind % IDX_MOD), proc->registers[reg_n], vm);
}
