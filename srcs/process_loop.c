/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:56:51 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/04 19:47:05 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
/*
void	run_cycle(t_vm *vm)
{
	t_list				*player;
	t_list				*process;

	cycle_n++;
	player = vm->players;
	while (player)
	{
		process = ((t_champion*)player->content)->processes;
		while (process)
		{
			if ()
		}
	}
}*/

void	vm_loop(t_vm *vm)
{
	while (vm->process_count)
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
		//run_cycle(vm);
	}
}
