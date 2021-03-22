/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcolo_distanza.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:49:53 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 18:06:26 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		calcolo_dist_tris(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	calc->dir_a = calc_dir(s_a, s_a->stack[calc->j]);
	calc->dist_a = calc_dist(s_a, s_a->stack[calc->j]);
	if (calc->j == 0)
		calc->prec_a = s_a->stack[s_a->len - 1];
	else
		calc->prec_a = s_a->stack[calc->j - 1];
}

static void		calc_dist_01(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	if (calc->dist_b > calc->dist_a)
		calc->arr_dist[calc->i] = calc->dist_b;
	else
		calc->arr_dist[calc->i] = calc->dist_a;
	calc->arr_strategy[calc->i] = 200 +
		(calc->dir_a * 10) + calc->dir_b;
	calc->not_find = 0;
}

static void		calc_dist_02(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	calc->arr_dist[calc->i] = calc->dist_a + calc->dist_b;
	calc->arr_strategy[calc->i] = 300 +
		(calc->dir_a * 10) + calc->dir_b;
	calc->not_find = 0;
}

static void		calcolo_dist_03(t_stack *s_a, t_stack *s_b, t_calcolo *c)
{
	c->not_find = 1;
	c->dir_b = calc_dir(s_b, s_b->stack[c->i]);
	c->dist_b = calc_dist(s_b, s_b->stack[c->i]);
	c->j = 0;
}

void			calcolo_dist(t_stack *s_a, t_stack *s_b, t_calcolo *c)
{
	calc_init(s_a, s_b, c);
	while (c->i < s_b->len)
	{
		calcolo_dist_03(s_a, s_b, c);
		while (c->j < s_a->len)
		{
			calcolo_dist_tris(s_a, s_b, c);
			if (s_b->stack[c->i] < s_a->stack[c->j] && s_b->stack[c->i] >
				c->prec_a && c->dir_a == c->dir_b)
			{
				calc_dist_01(s_a, s_b, c);
				break ;
			}
			else if (s_b->stack[c->i] < s_a->stack[c->j] && s_b->stack[c->i] >
				c->prec_a && c->dir_a != c->dir_b)
			{
				calc_dist_02(s_a, s_b, c);
				break ;
			}
			c->j++;
		}
		calcolo_dist_bis(s_a, s_b, c);
	}
	free(c->arr_dist);
	free(c->arr_strategy);
}
