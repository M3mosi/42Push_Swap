/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:57:57 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 17:10:56 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		index_min(t_stack *s)
{
	int min;
	int index;
	int i;

	i = 0;
	min = MAX_INT;
	index = 0;
	while (i < s->len)
	{
		if (s->stack[i] <= min)
		{
			min = s->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		index_max(t_stack *s)
{
	int max;
	int index;
	int i;

	i = 0;
	max = MIN_INT;
	index = 0;
	while (i < s->len)
	{
		if (s->stack[i] >= max)
		{
			max = s->stack[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		error(t_stack *s)
{
	int i;

	i = 0;
	while (i < s->len - 1)
	{
		if (s->stack[i] > s->stack[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	final_algo(t_stack *s_a, t_stack *s_b)
{
	int			same_moves;
	int			i;
	t_calcolo	calc;

	while (1)
	{
		calcolo_dist(s_a, s_b, &calc);
		if (calc.strategy == 111)
		{
			while (calc.i_a--)
				move(s_a, s_b, "ra");
			while (calc.i_b--)
				move(s_a, s_b, "rb");
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 121)
		{
			i = s_a->len - calc.i_a;
			while (i > 0)
			{
				move(s_a, s_b, "rra");
				i--;
			}
			while (calc.i_b--)
				move(s_a, s_b, "rb");
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 112)
		{
			i = s_b->len - calc.i_b;
			while (calc.i_a--)
				move(s_a, s_b, "ra");
			while (i > 0)
			{
				move(s_a, s_b, "rrb");
				i--;
			}
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 122)
		{
			i = s_a->len - calc.i_a;
			while (i > 0)
			{
				move(s_a, s_b, "rra");
				i--;
			}
			i = s_b->len - calc.i_b;
			while (i > 0)
			{
				move(s_a, s_b, "rrb");
				i--;
			}
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 211)
		{
			same_moves = 0;
			if (calc.i_a > 0 && calc.i_b > 0 && calc.i_a < calc.i_b)
				same_moves = calc.i_a;
			else if (calc.i_a > 0 && calc.i_b > 0 && calc.i_a > calc.i_b)
				same_moves = calc.i_b;
			calc.i_a -= same_moves;
			calc.i_b -= same_moves;
			while (same_moves--)
				move(s_a, s_b, "rr");
			while (calc.i_a--)
				move(s_a, s_b, "ra");
			while (calc.i_b--)
				move(s_a, s_b, "rb");
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 222)
		{
			same_moves = 0;
			if (calc.i_a > 0 && calc.i_b > 0 && s_a->len - calc.i_a <
				s_b->len - calc.i_b)
				same_moves = s_a->len - calc.i_a;
			else if (calc.i_a > 0 && calc.i_b > 0 && s_a->len - calc.i_a >
				s_b->len - calc.i_b)
				same_moves = s_b->len - calc.i_b;
			i = same_moves;
			while (i > 0)
			{
				move(s_a, s_b, "rrr");
				i--;
			}
			i = s_a->len - calc.i_a - same_moves;
			while (i > 0)
			{
				move(s_a, s_b, "rra");
				i--;
			}
			i = s_b->len - calc.i_b - same_moves;
			while (i > 0)
			{
				move(s_a, s_b, "rrb");
				i--;
			}
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 321)
		{
			i = s_a->len - calc.i_a;
			while (i > 0)
			{
				move(s_a, s_b, "rra");
				i--;
			}
			while (calc.i_b--)
				move(s_a, s_b, "rb");
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 312)
		{
			while (calc.i_a--)
				move(s_a, s_b, "ra");
			i = s_b->len - calc.i_b;
			while (i > 0)
			{
				move(s_a, s_b, "rrb");
				i--;
			}
			move(s_a, s_b, "pa");
		}
		else if (calc.strategy == 999)
			break ;
	}
	while (1)
	{
		if (index_min(s_a) == 0)
			break ;
		if (index_min(s_a) < (s_a->len / 2))
			move(s_a, s_b, "ra");
		else
			move(s_a, s_b, "rra");
	}
}
