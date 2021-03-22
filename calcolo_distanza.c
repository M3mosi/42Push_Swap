/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcolo_distanza.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:49:53 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 17:27:08 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	calcolo_dist(t_stack *s_a, t_stack *s_b, t_calcolo *calc)
{
	calc->min = MAX_INT;
	calc->arr_dist = ft_calloc(s_b->len, sizeof(int));
	calc->arr_strategy = ft_calloc(s_b->len, sizeof(int));
	calc->i_a = 0;
	calc->i_b = 0;
	calc->strategy = 999;
	calc->i = 0;
	while (calc->i < s_b->len)
	{
		calc->not_find = 1;
		calc->dir_b = calc_dir(s_b, s_b->stack[calc->i]);
		calc->dist_b = calc_dist(s_b, s_b->stack[calc->i]);
		calc->j = 0;
		while (calc->j < s_a->len)
		{
			calc->dir_a = calc_dir(s_a, s_a->stack[calc->j]);
			calc->dist_a = calc_dist(s_a, s_a->stack[calc->j]);
			if (calc->j == 0)
				calc->prec_a = s_a->stack[s_a->len - 1];
			else
				calc->prec_a = s_a->stack[calc->j - 1];
			if (s_b->stack[calc->i] < s_a->stack[calc->j] &&
				s_b->stack[calc->i] > calc->prec_a &&
				calc->dir_a == calc->dir_b)
			{
				if (calc->dist_b > calc->dist_a)
					calc->arr_dist[calc->i] = calc->dist_b;
				else
					calc->arr_dist[calc->i] = calc->dist_a;
				calc->arr_strategy[calc->i] = 200 +
					(calc->dir_a * 10) + calc->dir_b;
				calc->not_find = 0;
				break ;
			}
			else if (s_b->stack[calc->i] < s_a->stack[calc->j] &&
				s_b->stack[calc->i] > calc->prec_a &&
				calc->dir_a != calc->dir_b)
			{
				calc->arr_dist[calc->i] = calc->dist_a + calc->dist_b;
				calc->arr_strategy[calc->i] = 300 +
					(calc->dir_a * 10) + calc->dir_b;
				calc->not_find = 0;
				break ;
			}
			calc->j++;
		}
		if (calc->not_find)
		{
			calc->j = index_max(s_a);
			calc->dir_a = calc_dir(s_a, s_a->stack[calc->j]);
			calc->dist_a = calc_dist(s_a, s_a->stack[calc->j]);
			calc->j++;
			calc->arr_dist[calc->i] = calc->dist_a + calc->dist_b + 1;
			calc->arr_strategy[calc->i] = 100 +
				(calc->dir_a * 10) + calc->dir_b;
		}
		if (calc->arr_dist[calc->i] < calc->min)
		{
			calc->strategy = calc->arr_strategy[calc->i];
			calc->i_a = calc->j;
			calc->i_b = calc->i;
			calc->min = calc->arr_dist[calc->i];
		}
		calc->i++;
	}
	free(calc->arr_dist);
	free(calc->arr_strategy);
}
