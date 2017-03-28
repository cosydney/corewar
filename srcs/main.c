/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/10 13:45:25 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	show_winner(t_vm *vm)
{
	t_champion *cmp;

	cmp = id_to_champion(vm->players, vm->last_live_id);
	if (!cmp)
		return ;
	ft_printf("%c%s%c wins the corewar!\n", '"', cmp->header.prog_name, '"');
}

int			main(int argc, char **argv)
{
	t_vm		*vm;
	t_options	opt;

	if (!vm_init())
		exit(1);
	vm = vm_get();
	ft_bzero(&opt, sizeof(t_options));
	parse_args(argc, argv, vm, &opt);
	parse_champion(vm);
	init_processes(vm);
	vm_loop(vm, &opt);
	show_winner(vm);
	clear_vm(vm);
	return (0);
}
