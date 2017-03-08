/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/08 14:50:55 by amarzial         ###   ########.fr       */
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
	init_processes(vm);
	parse_instruction(vm, (t_process *)(vm->processes->content));
	vm_loop(vm);
	if (opt.dump)
		ft_print_mem(vm->memory, MEM_SIZE);
	clear_vm(vm);
//	sleep(10);
	return (0);
}

