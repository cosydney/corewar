/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:56:35 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/02 19:01:10 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			main(int ac, char **ar)
{
	t_vm	*vm;
//	int fd;

	(void)ac;
	(void)ar;

	if (!vm_init())
		exit(1);
	vm = vm_get();
//	if (ac == 2)
	{
		//fd = open(ar[1], O_RDONLY);
		//while
		ft_print_mem(vm->memory, MEM_SIZE);
	}
	return (0);
}

