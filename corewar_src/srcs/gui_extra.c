/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 15:07:15 by amarzial          #+#    #+#             */
/*   Updated: 2017/04/05 18:14:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void		gui_update_cursors(int state, int index, t_vm *vm)
{
	chtype	c;
	chtype	attr;
	int		x;
	int		y;

	(void)vm;
	y = (index * 3) / 192;
	x = (index * 3) % 192;
	move(y, x);
	c = mvinch(y, x);
	attr = c;
	if (!state)
		attr &= ~A_REVERSE;
	else
		attr |= A_REVERSE;
	attrset(attr & ~A_CHARTEXT);
	addch(c & A_CHARTEXT);
	c = mvinch(y, x + 1);
	addch(c & A_CHARTEXT);
	attroff(attr);
}

void		gui_highlight(int state, int index, t_vm *vm)
{
	chtype	c;
	chtype	attr;
	int		x;
	int		y;

	(void)vm;
	y = (index * 3) / 192;
	x = (index * 3) % 192;
	move(y, x);
	c = mvinch(y, x);
	attr = c;
	if (!state)
		attr &= ~A_BOLD;
	else
		attr |= A_BOLD;
	attrset(attr & ~A_CHARTEXT);
	addch(c & A_CHARTEXT);
	c = mvinch(y, x + 1);
	addch(c & A_CHARTEXT);
	attroff(attr);
}

void		gui_set_highlight(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (!vm->gui.fresh[1][i] && vm->gui.fresh[0][i])
		{
			gui_highlight(1, i, vm);
			vm->gui.fresh[1][i] = 1;
			vm->gui.fresh[0][i]--;
		}
		else if (vm->gui.fresh[1][i] && !vm->gui.fresh[0][i])
		{
			gui_highlight(0, i, vm);
			vm->gui.fresh[1][i] = 0;
		}
		else if (vm->gui.fresh[0][i])
			vm->gui.fresh[0][i]--;
		i++;
	}
}

void		gui_set_cursors(t_vm *vm)
{
	int		i;
	t_byte	*tmp;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (!vm->gui.curbuf[1][i] && vm->gui.curbuf[0][i])
			gui_update_cursors(1, i, vm);
		else if (vm->gui.curbuf[1][i] && !vm->gui.curbuf[0][i])
			gui_update_cursors(0, i, vm);
		i++;
	}
	tmp = vm->gui.curbuf[0];
	vm->gui.curbuf[0] = vm->gui.curbuf[1];
	vm->gui.curbuf[1] = tmp;
	ft_bzero(vm->gui.curbuf[0], MEM_SIZE);
}

void		show_champs(t_vm *vm)
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
