/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/03 14:05:41 by amarzial         ###   ########.fr       */
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
	if (opt.dump)
		ft_print_mem(vm->memory, MEM_SIZE);
	clear_vm(vm);
	return (0);
}

