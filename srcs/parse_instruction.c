/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:02:39 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/07 15:13:09 by abonneca         ###   ########.fr       */
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
/*
 **   static unsigned int add(unsigned int a, unsigned int b)
 **   {
 **   if(b == 0)
 **   return a;
 **   return add( a ^ b, (a & b) << 1);
 **   }
 */

static void	offset_pc(byte pc[REG_SIZE], unsigned int to_add)
{
	unsigned int pc_u;

	pc_u = regtou(pc);
	utoreg((pc_u +  to_add) % MEM_SIZE, pc);
}

void	input_params(t_vm *vm, t_process *process, int i, unsigned int *j)
{
	if (((process->act).encoding >> 2 * i) & REG_CODE)
	{
		(process->act).params[(process->act).op->arg_c - i][0] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
	}
	else if (((process->act).encoding >> 2 * i) & DIR_CODE)
	{
		(process->act).params[(process->act).op->arg_c - i][0] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
		(process->act).params[(process->act).op->arg_c - i][1] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
	}
	else if (((process->act).encoding >> 2 * i) & IND_CODE)
	{
		(process->act).params[(process->act).op->arg_c - i][0] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
		(process->act).params[(process->act).op->arg_c - i][1] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
		(process->act).params[(process->act).op->arg_c - i][2] = (vm->memory)[*j];
		*j = (*j + 1) % MEM_SIZE;
	}
}

void	parse_instruction(t_vm *vm, t_process *process)
{
	int		i;
	unsigned int		j;
	t_op 	*op_tab;

	i = 0;
	j = regtou(process->pc);
	op_tab = ft_get();
	while (i < 17)
	{
		if (op_tab[i].opcode == (vm->memory)[j])
			(process->act).op = &op_tab[i];
		++i;
	}
	if ((process->act).op)
	{
		j = (j + 1) % MEM_SIZE;
		(process->act).encoding = (vm->memory)[j];
		i = (process->act).op->arg_c;
		j = (j + 1) % MEM_SIZE;
		while (i >= 0)
		{
			input_params(vm, process, i, &j);
			--i;
		}
	}
	offset_pc(process->pc ,j);
}

/*
 	ft_printf("%i\n", regtou(process->pc));
 	ft_printf("%.2x %.2x %.2x %.2x\n", process->pc[0], process->pc[1], process->pc[2],process->pc[3]);
 	ft_printf("%.2x\n", (process->act).params[0][0]);
 	ft_printf("%.2x %.2x\n", (process->act).params[1][0], (process->act).params[1][1]);
 	ft_printf("%.2x %.2x\n", (process->act).params[2][0], (process->act).params[2][1]);
 */
