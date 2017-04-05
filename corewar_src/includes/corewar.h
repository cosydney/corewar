/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonneca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 13:39:59 by abonneca          #+#    #+#             */
/*   Updated: 2017/04/05 18:15:37 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <curses.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <libft.h>
# include <time.h>
# include "op.h"
# define UI_SPEED 100000
# define UI_TIME_NEW 20
# define REGTOU(x) ((unsigned int)(x[3] + (x[2]<<8) + (x[1]<<16) + (x[0]<<24)))

typedef unsigned char	t_byte;

enum					e_errcodes
{
	NO_ERROR,
	MALLOC_ERROR,
	GENERIC_ERROR,
	ARG_ERROR,
	TOO_MANY_PLAYERS,
	OPEN_ERROR,
	CLOSE_ERROR,
	READ_ERROR,
	LSEEK_ERROR,
	INVALID_FILE
};

typedef struct			s_op
{
	char		*mnemonic;
	char		arg_c;
	t_arg_type	ar[3];
	t_byte		opcode;
	size_t		cycles;
	char		*full_mess;
	char		encoding:1;
	char		index:1;
}						t_op;

typedef struct			s_options
{
	int		gui:1;
	int		dump:1;
	int		dump_cycles;
}						t_options;

typedef struct			s_gui
{
	int		speed;
	t_byte	*curbuf[2];
	t_byte	cursors[2][MEM_SIZE];
	int		fresh[2][MEM_SIZE];
}						t_gui;

typedef	struct			s_vm
{
	t_byte			memory[MEM_SIZE];
	t_list			*players;
	t_list			*processes;
	t_options		opt;
	t_gui			gui;
	unsigned int	player_count;
	unsigned int	total_cycles;
	unsigned int	cycle;
	unsigned int	cycle_to_die;
	unsigned int	checks;
	unsigned int	live_count;
	unsigned int	live_total;
	unsigned int	process_count;
	unsigned int	last_live_id;
}						t_vm;

typedef struct			s_champion
{
	struct s_header	header;
	unsigned int	id;
	char			*filename;
	unsigned int	offset;
	size_t			process_n;
}						t_champion;

typedef	struct			s_param
{
	t_arg_type	t;
	t_byte		value[REG_SIZE];
}						t_param;

typedef struct			s_action
{
	t_op	*op;
	t_byte	encoding;
	t_byte	pc[REG_SIZE];
	t_param	params[MAX_ARGS_NUMBER];
}						t_action;

typedef struct			s_process
{
	unsigned int	pid;
	t_champion		*parent;
	t_action		act;
	t_byte			registers[REG_NUMBER][REG_SIZE];
	t_byte			pc[REG_SIZE];
	int				carry:1;
	unsigned int	live_count;
	unsigned int	cycle_count;
}						t_process;

typedef void			(*t_callback)(t_process*, t_vm*);

extern t_op				g_op_tab[17];

t_vm					*vm_get();
void					init_processes(t_vm *vm);
t_process				*create_process(\
		unsigned int offset, t_champion *parent, t_vm *vm);

void					ft_print_mem(t_byte *memory, size_t size);
int						parse_args(\
		int argc, char **argv, t_vm *vm, t_options *opt);
int						create_champion(\
		t_vm *vm, char *str, unsigned int *custom_nbr, unsigned int *player_n);
void					parse_champion(t_vm *vm);
int						load_to_memory(\
		int fd, int current, t_vm *vm, unsigned int prog_size);
void					vm_loop(t_vm *vm, t_options *opt);

void					error_exit(int code, char *info);
void					parse_op(t_process *process, t_vm *vm);
int						parse_instruction(t_process *process, t_vm *vm);

void					utoreg(unsigned int n, t_byte reg[REG_SIZE]);
unsigned int			memtou(t_byte *mem, unsigned int offset, size_t size);
int						par_to_val(\
		int par, unsigned int *vars, t_process *proc, t_vm *vm);
int						lpar_to_val(\
		int par, unsigned int *vars, t_process *proc, t_vm *vm);
int						param_checker(t_process *proc);
void					st_to_mem(\
		unsigned int offset, t_byte reg[REG_SIZE], t_process *proc, t_vm *vm);

t_champion				*id_to_champion(t_list *champions, unsigned int id);

/*
** operations
*/
void					op_live(t_process *proc, t_vm *vm);
void					op_ld(t_process *proc, t_vm *vm);
void					op_st(t_process *proc, t_vm *vm);
void					op_add(t_process *proc, t_vm *vm);
void					op_sub(t_process *proc, t_vm *vm);
void					op_and(t_process *proc, t_vm *vm);
void					op_or(t_process *proc, t_vm *vm);
void					op_xor(t_process *proc, t_vm *vm);
void					op_zjump(t_process *proc, t_vm *vm);
void					op_ldi(t_process *proc, t_vm *vm);
void					op_sti(t_process *proc, t_vm *vm);
void					op_fork(t_process *proc, t_vm *vm);
void					op_lld(t_process *proc, t_vm *vm);
void					op_lldi(t_process *proc, t_vm *vm);
void					op_lfork(t_process *proc, t_vm *vm);
void					op_aff(t_process *proc, t_vm *vm);

/*
** free memory
*/
void					clear_vm(t_vm *vm);
void					kill_processes(t_vm *vm);
void					delete_process(void *content, size_t content_size);

/*
** user interface
*/
void					init_ui(void);
void					show_champs(t_vm *vm);
void					gui_show_champ(t_champion *champ, t_vm *vm);
void					gui_update_cursors(int state, int index, t_vm *vm);
void					gui_writemem(int offset, unsigned int id, t_vm *vm);
void					gui_set_cursors(t_vm *vm);
void					gui_set_highlight(t_vm *vm);

#endif
