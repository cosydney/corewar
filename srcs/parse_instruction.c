/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:02:39 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/28 19:35:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
 *  **   static unsigned int add(unsigned int a, unsigned int b)
 *   **   {
 *    **   if(b == 0)
 *     **   return a;
 *      **   return add( a ^ b, (a & b) << 1);
 *       **   }
 *        */

static void	set_param(t_vm *vm, t_byte *dest, unsigned int *offset, size_t size)
{
	size_t i;

	if (size > REG_SIZE)
		return ;
	i = 0;
	while (i < REG_SIZE - size)
		dest[i++] = 0;
	while (i < REG_SIZE)
	{
		dest[i] = (vm->memory)[*offset];
		*offset = (*offset + 1) % MEM_SIZE;
		i++;
	}
}

static void	input_params(t_vm *vm, t_process *process, int i, unsigned int *j)
{
	unsigned int	index;
	t_byte			code;

	index = (process->act).op->arg_c - i;
	code = (process->act.encoding >> (6 - (index << 1))) & 0x03;
	if (code == REG_CODE)
	{
		process->act.params[index].t = T_REG;
		set_param(vm, process->act.params[index].value, j, 1);
	}
	else if (code == DIR_CODE)
	{
		process->act.params[index].t = T_DIR;
		set_param(vm, process->act.params[index].value, j, \
			(process->act.op->index) ? IND_SIZE : DIR_SIZE);
	}
	else if (code == IND_CODE)
	{
		process->act.params[index].t = T_IND;
		set_param(vm, process->act.params[index].value, j, IND_SIZE);
	}
	else if (process->act.op->index || process->act.op->opcode == 0x01)
		set_param(vm, process->act.params[index].value, j, \
				(process->act.op->opcode == 0x01) ? 4 : IND_SIZE);
}

int		parse_instruction(t_process *process, t_vm *vm)
{
	int				i;
	unsigned int	pc;
	unsigned int	opcode;

	i = 0;
	pc = regtou(process->pc);
	opcode = process->act.op->opcode;
	process->act.encoding = 0;
	if (process->act.op->encoding)
		(process->act).encoding = (vm->memory)[pc++];
	i = (process->act).op->arg_c;
	pc %= MEM_SIZE;
	while (i > 0)
		input_params(vm, process, i--, &pc);
	process->cycle_count = process->act.op->cycles;
	utoreg(pc, process->pc);
	return (1);
}

/*
 *  **	ft_printf("%i\n", regtou(process->pc));
 *   **	ft_printf("%.2x %.2x %.2x %.2x\n", process->pc[0], process->pc[1], process->pc[2],process->pc[3]);
 *    **	ft_printf("%.2x\n", (process->act).params[0].value[0]);
 *     **	ft_printf("%.2x %.2x\n", (process->act).params[1].value[0], (process->act).params[1].value[1]);
 *      **	ft_printf("%.2x %.2x\n", (process->act).params[2].value[0], (process->act).params[2].value[1]);
 *       */
