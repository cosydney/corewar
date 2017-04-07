/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:56:51 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/04 19:09:45 by amarzial         ###   ########.fr       */
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
		if (!proc->act.op)
			parse_op(proc, vm);
		else if (!proc->cycle_count)
		{
			parse_instruction(proc, vm);
			g_operators[proc->act.op->opcode](proc, vm);
			proc->act.op = 0;
			ft_memcpy(proc->act.pc, proc->pc, REG_SIZE);
		}
		if (vm->opt.gui)
			vm->gui.curbuf[0][REGTOU(proc->act.pc)] = 1;
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
	usleep(vm->gui.speed);
}

static int	handle_input(int c, t_vm *vm)
{
	static int	running;

	if (c == ' ')
		running = !running;
	else if (c == '+' || c == '-')
	{
		speed_set(c, &(vm->gui.speed));
		mvprintw(69, 0, "SPEED:         %10u", vm->gui.speed);
		refresh();
	}
	else if (c == 'q')
		error_exit(NO_ERROR, "user closed");
	return (running);
}

void		vm_loop(t_vm *vm, t_options *opt)
{
	if (vm->opt.gui)
		screen_stuff(vm);
	while (vm->process_count && \
	(!opt->dump || (vm->total_cycles + 1 <= (unsigned int)opt->dump_cycles)))
	{
		if (vm->opt.gui && !handle_input(getch(), vm))
			continue;
		run_cycle(vm);
		if (vm->cycle >= vm->cycle_to_die)
			kill_processes(vm);
		vm->cycle++;
		vm->total_cycles++;
		if (vm->opt.gui)
			screen_stuff(vm);
	}
	if (opt->dump && vm->process_count)
		ft_print_mem(vm->memory, MEM_SIZE);
}
