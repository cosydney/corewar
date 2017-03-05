/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:39:59 by abonneca          #+#    #+#             */
/*   Updated: 2017/03/05 15:22:50 by abonneca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# include "op.h"

typedef unsigned char byte;

enum			e_errcodes
{
	MALLOC_ERROR= 1,
	GENERIC_ERROR,
	ARG_ERROR,
	TOO_MANY_PLAYERS,
	OPEN_ERROR,
	CLOSE_ERROR,
	READ_ERROR,
	LSEEK_ERROR,
	INVALID_FILE
};

typedef struct	s_op
{
	char		*mnemonic;
	char		arg_c;
	t_arg_type	ar[3];
	byte		opcode;
	size_t		cycles;
	char		*full_mess;
	char		reg:1;
	char		index:1;
}				t_op;

typedef	struct	s_vm
{
	byte			memory[MEM_SIZE];
	t_list			*players;
	unsigned int	player_count;
	int				cycle;
}				t_vm;

typedef struct		s_champion
{
	struct s_header	header;
	unsigned int	id;
	char			*filename;
	int				offset;
	t_list			*processes;
	size_t			process_n;
}				t_champion;

typedef struct	s_process
{
	byte	registers[REG_NUMBER][REG_SIZE];
	byte	pc[REG_SIZE];
	int		carry:1;
	t_op	*current;
	int		cycle_count;
}				t_process;

typedef struct	s_player
{
	t_process		*process;
	struct s_player	*next;

}				t_player;

typedef struct	s_options
{
	int		dump:1;
	int		dump_cycles;
}				t_options;

typedef	struct s_operation
{
	t_op	*op;
	byte	params_byte;
	byte	params[MAX_ARGS_NUMBER][REG_SIZE];
}		t_operation;

t_vm			*vm_get();
int				vm_init();

void			ft_print_mem(byte *memory, size_t size);
int				parse_args(int argc, char **argv, t_vm *vm, t_options *opt);
int				create_champion(t_vm *vm, char *str, unsigned int *custom_nbr, \
		unsigned int *player_n);
void			parse_champion(t_vm *vm);
int				load_to_memory(int fd, int current, t_vm *vm, \
		unsigned int prog_size);

void			error_exit(int code);
void			parse_instruction(char **argv);

/*
 ** free memory
 */
void			clear_vm(t_vm *vm);

#endif
