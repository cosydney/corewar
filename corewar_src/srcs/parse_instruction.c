/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:02:39 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/04 15:32:31 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	else if ((!process->act.op->encoding && process->act.op->index) || \
	process->act.op->opcode == 0x01)
		set_param(vm, process->act.params[index].value, j, \
				(process->act.op->opcode == 0x01) ? 4 : IND_SIZE);
}

int			parse_instruction(t_process *process, t_vm *vm)
{
	int				i;
	unsigned int	pc;

	i = 0;
	pc = REGTOU(process->pc);
	process->act.encoding = 0;
	if (process->act.op->encoding)
		(process->act).encoding = (vm->memory)[pc++];
	i = (process->act).op->arg_c;
	pc %= MEM_SIZE;
	ft_bzero(&(process->act.params), sizeof(t_param) * MAX_ARGS_NUMBER);
	while (i > 0)
		input_params(vm, process, i--, &pc);
	utoreg(pc, process->pc);
	return (1);
}
