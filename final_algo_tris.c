/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_tris.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:50:26 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 17:54:33 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		loop_01(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int i;

	if (calc->strategy == 111)
	{
		while (calc->i_a--)
			move(s_a, s_b, "ra");
		while (calc->i_b--)
			move(s_a, s_b, "rb");
		move(s_a, s_b, "pa");
	}
	if (calc->strategy == 121)
	{
		i = s_a->len - calc->i_a;
		while (i > 0)
		{
			move(s_a, s_b, "rra");
			i--;
		}
		while (calc->i_b--)
			move(s_a, s_b, "rb");
		move(s_a, s_b, "pa");
	}
}

void		loop_06(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int i;

	if (calc->strategy == 321)
	{
		i = s_a->len - calc->i_a;
		while (i > 0)
		{
			move(s_a, s_b, "rra");
			i--;
		}
		while (calc->i_b--)
			move(s_a, s_b, "rb");
		move(s_a, s_b, "pa");
	}
}

void		loop_07(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	int i;

	if (calc->strategy == 312)
	{
		while (calc->i_a--)
			move(s_a, s_b, "ra");
		i = s_b->len - calc->i_b;
		while (i > 0)
		{
			move(s_a, s_b, "rrb");
			i--;
		}
		move(s_a, s_b, "pa");
	}
}
