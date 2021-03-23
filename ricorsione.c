/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ricorsione.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:23:46 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/23 12:52:01 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct		s_var_rec
{
	int				deep;
	int				moves[1000];
	char			*func[11];
}					t_var_rec;


void	rec(t_stack *s_a, t_stack *s_b, int i, t_var_rec *vars)
{
	if (i  + 1> vars->deep)
		return ;
	if (error(s_a) == 0 && s_b->len == 0)
	{
		vars->deep = i;
		ft_print_arrint(s_a->stack, s_a->len, "");
		ft_printf("OKKKKK %d\n", i);
		return ;
	}
	for (int j = 0; j < 11; j++)
	{
		//stack_t copia_a
		ft_print_arrint(s_a->stack, s_a->len, "");
		ft_printf("\n");
		move(s_a, s_b, vars->func[j]);
		//rec(s_a, s_b, i + 1, vars);
	}
	sleep(100);
}

void	init_vars_rec(t_var_rec *vars)
{
	vars->deep = 10;
	vars->func[0] = "sa";
	vars->func[1] = "sb";
	vars->func[2] = "ss";
	vars->func[3] = "pa";
	vars->func[4] = "pb";
	vars->func[5] = "ra";
	vars->func[6] = "rb";
	vars->func[7] = "rr";
	vars->func[8] = "rra";
	vars->func[9] = "rrb";
	vars->func[10] = "rrr";
}

void	final_ricorsione(t_stack *s_a, t_stack *s_b)
{
	t_var_rec	vars;

	init_vars_rec(&vars);
	rec(s_a, s_b, 0, &vars);
	ft_printf("FINITO\n");
}
