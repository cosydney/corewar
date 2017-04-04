/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/04 19:12:12 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	show_winner(t_vm *vm)
{
	t_champion *cmp;

	cmp = id_to_champion(vm->players, vm->last_live_id);
	if (!cmp)
		return ;
	if (vm->opt.gui)
		mvprintw(66, 30, "Winner: %s", cmp->header.prog_name);
	else
		ft_printf("%c%s%c wins the corewar!\n", \
				'"', cmp->header.prog_name, '"');
}

static void	show_champs(t_vm *vm)
{
	t_list		*lst;
	t_champion	*champ;

	lst = vm->players;
	while (lst)
	{
		champ = (t_champion*)lst->content;
		gui_show_champ(champ, vm);
		lst = lst->next;
	}
}

int			main(int argc, char **argv)
{
	t_vm		*vm;

	if (!vm_init())
		exit(1);
	vm = vm_get();
	ft_bzero(&(vm->opt), sizeof(t_options));
	parse_args(argc, argv, vm, &(vm->opt));
	parse_champion(vm);
	if (vm->opt.gui)
	{
		init_ui();
		show_champs(vm);
	}
	init_processes(vm);
	vm_loop(vm, &(vm->opt));
	show_winner(vm);
	if (vm->opt.gui)
		while (getch() == -1)
			continue ;
	clear_vm(vm);
	return (0);
}
