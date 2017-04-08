/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/08 15:35:00 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	show_winner(t_vm *vm)
{
	t_champion *cmp;

	if (vm->process_count || vm->opt.dump)
		return ;
	cmp = id_to_champion(vm->players, vm->last_live_id);
	if (!cmp)
		return ;
	if (vm->opt.gui)
		mvprintw(66, 30, "Winner: %s", cmp->header.prog_name);
	else
	{
		ft_printf("\nAnd the winner is...\n\tPlayer %u: \"%s\"\n", \
				cmp->id, cmp->header.prog_name);
		if (vm->player_count == 1)
			ft_putstr("Wait!\nDo you think that fighting alone is fair?\n\
I'm sorry no prize for you. Show me a REAL fight\n");
		else
			ft_putstr("Congrats dude! You are the best, for now\n");
	}
}

static void	welcome_message(t_list *players)
{
	t_champion	*champ;

	ft_putstr("Welcome to the corewar!\nToday match we have \
			the following champions fighting for glory and \"memory\":\n");
	while (players)
	{
		champ = (t_champion*)players->content;
		ft_printf("\tPlayer %u, %u bytes big. \"%s\" (\"%s\")!\n", \
				champ->id, champ->header.prog_size, \
				champ->header.prog_name, champ->header.comment);
		players = players->next;
	}
}

static void	print_usage(void)
{
	ft_printf(\
"Usage:\n./corewar [-dump N | -gui] <[-n N] champion1.cor> <...>\n\n\
\t-dump N	: Print a dump of the memory after N cycles\n\
\t-gui	: Runs the program with an interactive graphical interface\n\n\
\t-n N	: Used before a champion filename. Specifies the champion number\n");
}

int			main(int argc, char **argv)
{
	t_vm		*vm;

	if (!(vm = vm_get()))
		error_exit(MALLOC_ERROR, "VM");
	ft_bzero(&(vm->opt), sizeof(t_options));
	parse_args(argc, argv, vm, &(vm->opt));
	parse_champion(vm);
	if (vm->players)
	{
		welcome_message(vm->players);
		if (vm->opt.gui)
		{
			init_ui();
			show_champs(vm);
		}
		init_processes(vm);
		vm_loop(vm, &(vm->opt));
		show_winner(vm);
		while (vm->opt.gui && (getch() == -1))
			continue ;
	}
	else
		print_usage();
	clear_vm(vm);
	return (0);
}
