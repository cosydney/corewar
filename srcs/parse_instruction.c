/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:02:39 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/07 15:49:23 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
 **   static unsigned int add(unsigned int a, unsigned int b)
 **   {
 **   if(b == 0)
 **   return a;
 **   return add( a ^ b, (a & b) << 1);
 **   }
 */

static void	offset_pc(byte pc[REG_SIZE], unsigned int to_add)
{
	unsigned int pc_u;

	pc_u = regtou(pc);
	utoreg((pc_u +  to_add) % MEM_SIZE, pc);
}

void	input_ind(t_vm *vm, t_process *process, int index, unsigned int *j)
{
	(process->act).params[index].t = T_IND;
	(process->act).params[index].value[0] = (vm->memory)[*j];
	*j = (*j + 1) % MEM_SIZE;
	(process->act).params[index].value[1] = (vm->memory)[*j];
	*j = (*j + 1) % MEM_SIZE;
	(process->act).params[index].value[2] = (vm->memory)[*j];
	*j = (*j + 1) % MEM_SIZE;
}

void	input_params(t_vm *vm, t_process *process, int i, unsigned int *j)
{
	unsigned int index;

	index = (process->act).op->arg_c - i;
	if (((process->act).encoding >> 2 * i) & REG_CODE)
	{ 
		(process->act).params[index].t = T_REG;
		(process->act).params[index].value[0] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
	}
	else if (((process->act).encoding >> 2 * i) & DIR_CODE)
	{
		(process->act).params[index].t = T_DIR;
		(process->act).params[index].value[0] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
		(process->act).params[index].value[1] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
	}
	else if (((process->act).encoding >> 2 * i) & IND_CODE)
		input_ind(vm, process, index, j);
}

void	parse_instruction(t_vm *vm, t_process *process)
{
	int		i;
	unsigned int		j;

	i = 0;
	j = regtou(process->pc);
	while (i < 17)
	{
		if (op_tab[i].opcode == (vm->memory)[j])
			(process->act).op = &op_tab[i];
		++i;
	}
	if ((process->act).op)
	{
		j = (j + 1) % MEM_SIZE;
		(process->act).encoding = (vm->memory)[j];
		i = (process->act).op->arg_c;
		j = (j + 1) % MEM_SIZE;
		while (i >= 0)
			input_params(vm, process, i--, &j);
	}
	offset_pc(process->pc, j);
}

/*
 **	ft_printf("%i\n", regtou(process->pc));
 **	ft_printf("%.2x %.2x %.2x %.2x\n", process->pc[0], process->pc[1], process->pc[2],process->pc[3]);
 **	ft_printf("%.2x\n", (process->act).params[0].value[0]);
 **	ft_printf("%.2x %.2x\n", (process->act).params[1].value[0], (process->act).params[1].value[1]);
 **	ft_printf("%.2x %.2x\n", (process->act).params[2].value[0], (process->act).params[2].value[1]);
 */
