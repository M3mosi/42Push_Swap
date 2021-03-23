/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:56:32 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/23 11:26:09 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"

# define FBLACK		"\033[30m"
# define FRED		"\033[31m"
# define FGREEN		"\033[32m"
# define FYELLOW	"\033[33m"
# define FBLUE		"\033[34m"
# define FPURPLE	"\033[35m"
# define D_FGREEN	"\033[6m"
# define FWHITE		"\033[7m"
# define BBLACK		"\e[40m"
# define BRED		"\e[41m"
# define BGREEN		"\e[42m"
# define BYELLOW	"\e[43m"
# define BBLUE		"\e[44m"
# define BPURPLE	"\e[45m"
# define D_BGREEN	"\e[46m"
# define BWHITE		"\e[47m"
# define FCYAN		"\x1b[36m"
# define NONE		"\033[0m"
# define MIN_INT	-2147483648
# define MAX_INT	2147483647
# define MOVES_SIZE	11

typedef struct		s_stack
{
	int				len;
	int				*stack;
	int				error;
	int				color;
	int				visual;
	int				file;
	char			*filepath;
	int				tot_move;
	char			**check_moves;
	int				*indexed;
}					t_stack;

typedef struct		s_calcolo
{
	int				strategy;
	int				i_a;
	int				i_b;
	int				min;
	int				dir_b;
	int				dist_b;
	int				dir_a;
	int				dist_a;
	int				not_find;
	int				*arr_dist;
	int				*arr_strategy;
	int				i;
	int				j;
	int				prec_a;
}					t_calcolo;

typedef struct		s_h
{
	int				*solution[10000];
	char			mov[11][3];
}					t_h;

typedef struct		s_lis
{
	int				*arr;
	int				len;
	int				max;
}					t_lis;

int					check_empty(t_stack *stack);
void				do_sasb(t_stack *stack);
void				do_ss(t_stack *stack_a, t_stack *stack_b);
void				shift_stack(t_stack *stack, int mod);
void				shift_rev_stack(t_stack *stack, int mod);
void				do_push(t_stack *stack_a, t_stack *stack_b);
void				rotate_one_stack(t_stack *stack);
void				rotate_two_stack(t_stack *stack_a, t_stack *stack_b);
void				rotate_rev_one_stack(t_stack *stack);
void				rotate_rev_two_stack(t_stack *stack_a, t_stack *stack_b);
char				**define_moves(void);
void				move(t_stack *stack_a, t_stack *stack_b, char *move);
void				print_stack(t_stack *stack_a, t_stack *stack_b);
void				algorithm(t_stack *stack_a, t_stack *stack_b);
void				final_algo_start(t_stack *stack_a, t_stack *stack_b);
void				final_algo(t_stack *s_a, t_stack *s_b);
void				lis(t_lis *lis, t_stack *s);
void				lis_select(t_lis *lis);
int					calc_dir(t_stack *stack, int n);
int					calc_dist(t_stack *stack, int n);
int					error(t_stack *s);
int					is_a_flag(char *str);
int					count_for_alloc(int argc, char **argv);
t_stack				parse_multi(int argc, char **argv, t_stack stack, int j);
int					mparse_helper(char **argv, char **split, int i, int *out);
void				flag_taker(t_stack *stack, int argc, char **argv);
void				calcolo_dist(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
int					index_max(t_stack *s);
t_stack				init_stack(t_stack stack, int len);
int					is_ordinated(t_stack *stack);
void				indexing(t_stack *stack, int j);
void				calc_init(t_stack *s_b, t_calcolo *calc);
void				calcolo_dist_bis(t_stack *s_a, t_calcolo *calc);
void				loop_01(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
void				loop_02(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
void				loop_03(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
void				loop_04(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
void				loop_05(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
void				loop_06(t_stack *s_a, t_stack *s_b, t_calcolo *calc);
void				loop_07(t_stack *s_a, t_stack *s_b, t_calcolo *calc);

#endif
