/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:16:44 by amarzial          #+#    #+#             */
/*   Updated: 2017/03/29 20:04:19 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include "corewar.h"

static void	showbyte(t_byte b)
{
	char	*base;

	base = "0123456789ABCDEF";
	addch(base[b / 16]);
	addch(base[b % 16]);
}

static void	showmem()
{
	int		i;
	int		pos[2];
	t_vm	*vm;

	vm = vm_get();
	pos[0] = 0;
	pos[1] = 0;
	i = 0;
	while (i < MEM_SIZE)
	{
		move(pos[0], pos[1]);
		showbyte(vm->memory[i++]);
		pos[1] += 3;
		if (pos[1] >= (192) && !(pos[1] = 0))
			pos[0]++;
	}
	refresh();
}

void		gui_show_champ(t_champion *champ, t_vm *vm)
{
	unsigned int	i;

	attron(COLOR_PAIR(champ->id % CHAMP_MAX_SIZE + 1));
	i = 0;
	while (i < champ->header.prog_size)
	{
		move((champ->offset + i) * 3 / 192, (champ->offset + i) * 3 % 192);
		showbyte(vm->memory[champ->offset + i]);
		i++;
	}
	attroff(COLOR_PAIR(champ->id % CHAMP_MAX_SIZE + 1));
	refresh();
}

void		gui_writemem(int offset, unsigned int id, t_vm *vm)
{
	int		i;
	int		x;
	int		y;
	chtype	c;

	i = 0;
	attron(COLOR_PAIR(id % CHAMP_MAX_SIZE + 1));
	while (i < REG_SIZE)
	{
		y = (offset * 3) / 192;
		x = (offset * 3) % 192;
		c = mvinch(y, x) & (A_REVERSE | A_BOLD);
		attron(c);
		move(offset * 3 / 192, offset * 3 % 192);
		showbyte(vm->memory[offset]);
		attroff(c);
		offset = (offset + 1) % MEM_SIZE;
		i++;
	}
	attroff(COLOR_PAIR(id % CHAMP_MAX_SIZE + 1));
}

void		gui_update_cursors(int state, int index, t_vm *vm)
{
	chtype	c;
	chtype	attr;
	int		x;
	int		y;

	(void) vm;
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

	(void) vm;
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

void		init_ui(void)
{
	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, 1);
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED,     COLOR_BLACK);
	init_pair(2, COLOR_GREEN,     COLOR_BLACK);
	init_pair(3, COLOR_YELLOW,     COLOR_BLACK);
	init_pair(4, COLOR_BLUE,     COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA,     COLOR_BLACK);
	init_pair(6, COLOR_CYAN,     COLOR_BLACK);
	init_pair(7, COLOR_WHITE,     COLOR_BLACK);
	showmem();
}


