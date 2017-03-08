/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:56:00 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/08 19:49:22 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ld_to_mem(unsigned int offset, byte reg[REG_SIZE], t_vm *vm)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		vm->memory[(offset + i) % MEM_SIZE] = reg[i];
		++i;
	}
}

static void		ld_to_reg(byte reg_src[REG_SIZE], byte reg_param[REG_SIZE])
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		reg_param[i] = reg_src[i];
		++i;
	}
}

void			op_st(t_process *proc, t_vm *vm)
{
	t_param			reg_param;
	byte			*reg_src;

	reg_src = proc->act.params[0].value;
	reg_param = proc->act.params[1];
	proc->carry = (reg_src) ? 0 : 1;
	if (reg_param.t == T_REG)
		ld_to_reg(reg_src, reg_param.value);
	else if (reg_param.t == T_IND)
		ld_to_mem(regtou(reg_param.value), reg_src, vm);
}
