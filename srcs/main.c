/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/05 16:50:04 by amarzial         ###   ########.fr       */
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
