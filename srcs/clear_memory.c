/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 20:02:48 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/28 16:10:42 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void		delete_process(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void	delete_champion(void *content, size_t content_size)
{

	(void)content_size;
	free(content);
}

void		clear_vm(t_vm *vm)
{
	ft_lstdel(&(vm->players), delete_champion);
	ft_lstdel(&(vm->processes), delete_process);
	free(vm);
	if (vm->opt.gui)
		endwin();
}
