/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:56:51 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/29 19:50:29 by amarzial         ###   ########.fr       */
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
	[0x0a] = op_ldi,
	[0x0b] = op_sti,
	[0x0c] = op_fork,
	[0x0d] = op_lld,
	[0x0e] = op_lldi,
	[0x0f] = op_lfork,
	[0x10] = op_aff
};

void		run_cycle(t_vm *vm)
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
		if (vm->opt.gui)
			vm->gui.curbuf[0][regtou(proc->act.pc)] = 1;
		if (proc->cycle_count)
			proc->cycle_count--;
		process = process->next;
	}
}

static void	speed_set(int c, int *speed)
{
	int factor;

	factor = *speed * 20 / 100;
	if (c == '-')
		*speed = ft_min(*speed + factor, 1000000);
	else if (c == '+')
		*speed = ft_max(*speed - factor, 1000);
}

static void	screen_stuff(t_vm *vm)
{
	mvprintw(66, 0, "CYCLE NUMBER:  %10u", vm->total_cycles);
	mvprintw(67, 0, "CYCLE TO DIE:  %10u", vm->cycle_to_die);
	mvprintw(68, 0, "PROCESS COUNT: %10u", vm->process_count);
	mvprintw(69, 0, "SPEED:         %10u", vm->gui.speed);
	gui_set_highlight(vm);
	gui_set_cursors(vm);
	refresh();
	speed_set(getch(), &(vm->gui.speed));
	usleep(vm->gui.speed);
}

void		vm_loop(t_vm *vm, t_options *opt)
{
	while (vm->process_count && \
	(!opt->dump || (vm->total_cycles < (unsigned int)opt->dump_cycles)))
	{
		vm->cycle++;
		vm->total_cycles++;
		if (vm->cycle >= vm->cycle_to_die)
		{
			kill_processes(vm);
			vm->checks++;
			if ((vm->live_count > NBR_LIVE || vm->checks >= MAX_CHECKS) && \
			!(vm->checks = 0))
				vm->cycle_to_die -= ft_min(CYCLE_DELTA, vm->cycle_to_die);
			vm->cycle = 0;
			vm->live_count = 0;
		}
		run_cycle(vm);
		if (vm->opt.gui)
			screen_stuff(vm);
	}
	if (opt->dump && vm->process_count)
		ft_print_mem(vm->memory, MEM_SIZE);
}
