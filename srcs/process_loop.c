/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:56:51 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/08 16:01:28 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

t_callback	g_operators[17] =
{
	[0x00] = 0,
	[0x01] = op_live,
	[0x02] = op_ld,
	[0x03] = op_st,
	[0x04] = op_add,
	[0x05] = op_sub,
	[0x06] = op_and,
	[0x07] = op_or,
	[0x08] = op_xor,
	[0x09] = op_zjump,
	[0x0d] = op_lld
};

void	run_cycle(t_vm *vm)
{
	t_list				*process;
	t_process			*proc;

	process = vm->processes;
	while (process)
	{
		proc = (t_process*)process->content;
		if (!proc->cycle_count)
		{
			if (proc->act.op)
				g_operators[proc->act.op->opcode](proc, vm);
			parse_instruction(proc, vm);
		}
		if (proc->cycle_count)
			proc->cycle_count--;
		process = process->next;
	}
}

void	vm_loop(t_vm *vm, t_options *opt)
{
	while (vm->process_count && \
	(!opt->dump || (vm->total_cycles < opt->dump_cycles)))
	{
		vm->cycle++;
		vm->total_cycles++;
		if (vm->cycle >= vm->cycle_to_die)
		{
			kill_processes(vm);
			vm->checks++;
			if ((vm->live_count > NBR_LIVE || vm->checks >= MAX_CHECKS) && \
			!(vm->checks = 0))
				vm->cycle_to_die -= CYCLE_DELTA;
			vm->cycle = 0;
			vm->live_count = 0;
		}
		run_cycle(vm);
	}
	if (opt->dump)
		ft_print_mem(vm->memory, MEM_SIZE);
}
