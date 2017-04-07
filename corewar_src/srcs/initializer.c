/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 15:00:49 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/05 16:17:47 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"
#include <limits.h>

t_process	*create_process(unsigned int offset, t_champion *parent, t_vm *vm)
{
	static unsigned int	pid;
	t_process			proc;
	t_list				*tmp;

	pid++;
	ft_bzero(&proc, sizeof(t_process));
	proc.pid = pid;
	proc.parent = parent;
	utoreg(offset % MEM_SIZE, proc.pc);
	utoreg(UINT_MAX - (parent->id - 1), proc.registers[0]);
	if (vm->opt.gui)
		vm->gui.curbuf[0][REGTOU(proc.pc)] = 1;
	if (!(tmp = ft_lstnew(&proc, sizeof(t_process))))
		error_exit(MALLOC_ERROR, 0);
	ft_lstadd(&(vm->processes), tmp);
	parent->process_n++;
	vm->process_count++;
	return ((t_process*)tmp->content);
}

void		init_processes(t_vm *vm)
{
	t_champion	*champ;
	t_list		*players;

	players = vm->players;
	while (players)
	{
		champ = (t_champion*)players->content;
		create_process(champ->offset, champ, vm);
		players = players->next;
	}
}
