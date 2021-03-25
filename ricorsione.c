/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ricorsione.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 10:23:46 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/25 12:47:34 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack		*ft_copy_stack(t_stack *s, int deep)
{
	t_stack	*copia;
	int		i;

	copia = malloc(1 * sizeof(t_stack));
	copia->len = s->len;
	copia->tot_move = s->tot_move;
	if (!(copia->stack = ft_arr_dup(s->stack, s->len)))
		exit(0);
	if (!(copia->indexed = ft_arr_dup(s->indexed, s->len)))
		exit(0);
	if (!(copia->moves = malloc((deep + 1) * sizeof(int))))
		exit(0);
	copia->visual = s->visual;
	copia->ricorsione = s->ricorsione;
	i = 0;
	while (i < deep)
	{
		copia->moves[i] = s->moves[i];
		i++;
	}
	return (copia);
}

void		free_stack(t_stack *s)
{
	free(s->stack);
	free(s->indexed);
	free(s->moves);
	free(s);
}

void		rec(t_stack *s_a, t_stack *s_b, int i, t_var_rec *vars)
{
	t_stack *copia_a;
	t_stack	*copia_b;
	int		j;

	if (i + 1 > vars->deep)
	{
		return ;
	}
	else if (!s_b->len && is_ordinated(s_a))
		return (return_function(vars, s_a, i));
	j = -1;
	while (++j < 11)
	{
		if ((s_b->len == 0 && not_ok_b(j)) ||
		(s_a->len == 0 && not_ok_a(j)))
			continue ;
		copia_a = ft_copy_stack(s_a, i);
		copia_b = ft_copy_stack(s_b, i);
		copia_a->moves[i] = j;
		move(copia_a, copia_b, vars->func[j]);
		rec(copia_a, copia_b, i + 1, vars);
		free_stack(copia_a);
		free_stack(copia_b);
	}
}

void		init_vars_rec(t_var_rec *vars)
{
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
	vars->moves = NULL;
	vars->tot_moves = 0;
}

void		final_ricorsione(t_stack *s_a, t_stack *s_b)
{
	t_var_rec	vars;

	if (is_ordinated(s_a))
		return ;
	s_a->ricorsione = 1;
	init_vars_rec(&vars);
	if (s_a->len <= 3)
		vars.deep = 3;
	else
		vars.deep = 12;
	if (s_a->visual == 1)
	{
		s_a->visual = 0;
		rec(s_a, s_b, 0, &vars);
		s_a->visual = 1;
	}
	else
		rec(s_a, s_b, 0, &vars);
	print_moves_rec(s_a, s_b, vars);
	free(vars.moves);
}
