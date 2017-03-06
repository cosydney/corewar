/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:02:39 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/06 16:30:57 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_op	*ft_get(void)
{
	static t_op    op_tab[17] =
	{
		{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
		{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
		{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
		{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
		{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
		{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
			"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
		{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
			"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
		{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
			"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
		{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
		{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
			"load index", 1, 1},
		{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
			"store index", 1, 1},
		{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
		{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
		{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
			"long load index", 1, 1},
		{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
		{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
		{0, 0, {0}, 0, 0, 0, 0, 0}
	};
	return (op_tab);
}

//vm or (vm->memory), process
void	parse_instruction(t_vm *vm, t_process *process)
{


	t_action	operation;
	int		i;
	int		j;
	t_op 	*op_tab;
	i = 0;
	j = 0;
	op_tab = ft_get();

//	while (i < MEM_SIZE)
//		ft_printf("%.2hhx ", (vm->memory)[i++]);
	process->cycle_count = 0;
	ft_bzero(&operation, sizeof(t_action));
	while (i < 17)
	{
		if (op_tab[i].opcode == (vm->memory)[j])
			operation.op = &op_tab[i];
		++i;
	}
	if (operation.op)
		operation.encoding = (vm->memory)[++j];
	i = operation.op->arg_c;
	++j;
	while (i >= 0)
	{
		if ((operation.encoding >> 2 * i) & REG_CODE)
			operation.params[operation.op->arg_c - i][0] = (vm->memory)[j++];
		else if ((operation.encoding >> 2 * i) & DIR_CODE)
		{
			operation.params[operation.op->arg_c - i][0] = (vm->memory)[j++];
			operation.params[operation.op->arg_c - i][1] = (vm->memory)[j++];
		}
		else if ((operation.encoding >> 2 * i) & IND_CODE)
		{
			operation.params[operation.op->arg_c - i][0] = (vm->memory)[j++];
			operation.params[operation.op->arg_c - i][1] = (vm->memory)[j++];
			operation.params[operation.op->arg_c - i][2] = (vm->memory)[j++];
		}
		--i;
	}
	/*
	ft_printf("%.2x\n", operation.params[0][0]);
	ft_printf("%.2x %.2x\n", operation.params[1][0], operation.params[1][1]);
	ft_printf("%.2x %.2x\n", operation.params[2][0], operation.params[2][1]);
	*/
}
