/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ricorsione2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:02:23 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 11:16:04 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		return_function(t_var_rec *vars, t_stack *s_a, int i)
{
	vars->tot_moves = i;
	vars->deep = -1;
	free(vars->moves);
	vars->moves = ft_arr_dup(s_a->moves, i + 1);
	return ;
}

int			not_ok_b(int j)
{
	if (j == 1 || j == 2 || j == 3 || j == 6 || j == 7 || j == 9 || j == 10)
		return (1);
	return (0);
}

int			not_ok_a(int j)
{
	if (j == 0 || j == 2 || j == 4 || j == 5 || j == 7 || j == 8 || j == 10)
		return (1);
	return (0);
}

void		print_moves_rec(t_stack *s_a, t_stack *s_b, t_var_rec vars)
{
	int i;

	i = 0;
	while (i < vars.tot_moves)
	{
		ft_printf("%s\n", vars.func[vars.moves[i]]);
		move(s_a, s_b, vars.func[vars.moves[i]]);
		i++;
	}
}
