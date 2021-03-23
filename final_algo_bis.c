/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:34:13 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/23 11:21:39 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		loop_02(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int i;

	if (calc->strategy == 112)
	{
		i = s_b->len - calc->i_b;
		while (calc->i_a--)
			move(s_a, s_b, "ra");
		while (i > 0)
		{
			move(s_a, s_b, "rrb");
			i--;
		}
		move(s_a, s_b, "pa");
	}
}

void		loop_03(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int i;

	if (calc->strategy == 122)
	{
		i = s_a->len - calc->i_a;
		while (i > 0)
		{
			move(s_a, s_b, "rra");
			i--;
		}
		i = s_b->len - calc->i_b;
		while (i > 0)
		{
			move(s_a, s_b, "rrb");
			i--;
		}
		move(s_a, s_b, "pa");
	}
}

void		loop_04(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int same_moves;

	if (calc->strategy == 211)
	{
		same_moves = 0;
		if (calc->i_a > 0 && calc->i_b > 0 && calc->i_a < calc->i_b)
			same_moves = calc->i_a;
		else if (calc->i_a > 0 && calc->i_b > 0 && calc->i_a > calc->i_b)
			same_moves = calc->i_b;
		calc->i_a -= same_moves;
		calc->i_b -= same_moves;
		while (same_moves--)
			move(s_a, s_b, "rr");
		while (calc->i_a--)
			move(s_a, s_b, "ra");
		while (calc->i_b--)
			move(s_a, s_b, "rb");
		move(s_a, s_b, "pa");
	}
}

static void	loop_05_01(t_stack *s_a, t_stack *s_b, t_calcolo *c, int same_moves)
{
	int i;

	i = s_a->len - c->i_a - same_moves;
	while (i > 0)
	{
		move(s_a, s_b, "rra");
		i--;
	}
	i = s_b->len - c->i_b - same_moves;
	while (i > 0)
	{
		move(s_a, s_b, "rrb");
		i--;
	}
}

void		loop_05(t_stack *s_a, t_stack *s_b, t_calcolo *c)
{
	int i;
	int same_moves;

	if (c->strategy == 222)
	{
		same_moves = 0;
		if (c->i_a > 0 && c->i_b > 0 && s_a->len - c->i_a < s_b->len - c->i_b)
			same_moves = s_a->len - c->i_a;
		else if (c->i_a > 0 && c->i_b > 0 && s_a->len - c->i_a >
			s_b->len - c->i_b)
			same_moves = s_b->len - c->i_b;
		i = same_moves;
		while (i > 0)
		{
			move(s_a, s_b, "rrr");
			i--;
		}
		loop_05_01(s_a, s_b, c, same_moves);
		move(s_a, s_b, "pa");
	}
}
