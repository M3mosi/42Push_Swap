/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:57:57 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 15:37:38 by dmalori          ###   ########.fr       */
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

void	calcolo_dist(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int *arr_dist;
	int *arr_strategy;
	int i;
	int j;
	int prec_a;

	calc->min = MAX_INT;
	arr_dist = ft_calloc(s_b->len, sizeof(int));
	arr_strategy = ft_calloc(s_b->len, sizeof(int));
	calc->i_a = 0;
	calc->i_b = 0;
	calc->strategy = 999;
	i = 0;
	while (i < s_b->len)
	{
		calc->not_find = 1;
		calc->dir_b = calc_dir(s_b, s_b->stack[i]);
		calc->dist_b = calc_dist(s_b, s_b->stack[i]);
		j = 0;
		while (j < s_a->len)
		{
			calc->dir_a = calc_dir(s_a, s_a->stack[j]);
			calc->dist_a = calc_dist(s_a, s_a->stack[j]);
			if (j == 0)
				prec_a = s_a->stack[s_a->len - 1];
			else
				prec_a = s_a->stack[j - 1];
			if (s_b->stack[i] < s_a->stack[j] && s_b->stack[i] >
				prec_a && calc->dir_a == calc->dir_b)
			{
				if (calc->dist_b > calc->dist_a)
					arr_dist[i] = calc->dist_b;
				else
					arr_dist[i] = calc->dist_a;
				arr_strategy[i] = 200 + (calc->dir_a * 10) + calc->dir_b;
				calc->not_find = 0;
				break ;
			}
			else if (s_b->stack[i] < s_a->stack[j] && s_b->stack[i] >
				prec_a && calc->dir_a != calc->dir_b)
			{
				arr_dist[i] = calc->dist_a + calc->dist_b;
				arr_strategy[i] = 300 + (calc->dir_a * 10) + calc->dir_b;
				calc->not_find = 0;
				break ;
			}
			j++;
		}
		if (calc->not_find)
		{
			j = index_max(s_a);
			calc->dir_a = calc_dir(s_a, s_a->stack[j]);
			calc->dist_a = calc_dist(s_a, s_a->stack[j]);
			j++;
			arr_dist[i] = calc->dist_a + calc->dist_b + 1;
			arr_strategy[i] = 100 + (calc->dir_a * 10) + calc->dir_b;
		}
		if (arr_dist[i] < calc->min)
		{
			calc->strategy = arr_strategy[i];
			calc->i_a = j;
			calc->i_b = i;
			calc->min = arr_dist[i];
		}
		i++;
	}
	free(arr_dist);
	free(arr_strategy);
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
		ft_printf("MOVE %d\n", s_a->tot_move);
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
