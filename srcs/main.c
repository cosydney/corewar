/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/06 16:30:11 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
	parse_instruction(vm, (t_process *)((t_champion *)(vm->players->content))->processes->content);
	init_processes(vm);
	vm_loop(vm);
	if (opt.dump)
		ft_print_mem(vm->memory, MEM_SIZE);
	clear_vm(vm);
//	sleep(10);
	return (0);
}

