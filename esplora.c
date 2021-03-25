/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esplora.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:28:02 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/25 14:39:30 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void		init_stack_algo(t_stack *stack_a, t_stack *stack_b,
	t_stack *copia_a, t_stack *copia_b)
{
	copia_a->len = stack_a->len;
	copia_b->len = stack_b->len;
	copia_a->tot_move = 0;
	if (!(copia_a->stack = ft_arr_dup(stack_a->stack, stack_a->len)))
		exit(0);
	if (!(copia_a->indexed = ft_arr_dup(stack_a->indexed, stack_a->len)))
		exit(0);
	if (!(copia_b->stack = ft_arr_dup(stack_b->stack, stack_a->len)))
		exit(0);
	if (!(copia_b->indexed = ft_arr_dup(stack_b->indexed, stack_a->len)))
		exit(0);
	copia_a->visual = 0;
	copia_b->visual = 0;
	copia_a->ricorsione = 1;
	copia_b->ricorsione = 1;
}

static void		free_stack_algo(t_stack *s)
{
	free(s->stack);
	free(s->indexed);
	free(s);
}

int				esplora(t_stack *stack_a, t_stack *stack_b)
{
	int		ret;
	t_lis	res_lis;
	t_stack	*copia_a;
	t_stack	*copia_b;

	ret = 0;
	copia_a = malloc(1 * sizeof(t_stack));
	copia_b = malloc(1 * sizeof(t_stack));
	init_stack_algo(stack_a, stack_b, copia_a, copia_b);
	if (!(res_lis.arr = ft_calloc(stack_a->len + 1, sizeof(int))))
		exit(0);
	ft_init_array_num(res_lis.arr, stack_a->len, 1);
	res_lis.len = stack_a->len;
	lis(&res_lis, stack_a);
	lis_select(&res_lis);
	final_algo_helper(copia_a, copia_b, &res_lis);
	free(res_lis.arr);
	final_algo(copia_a, copia_b);
	if (copia_a->tot_move > 5500)
		ret = 1;
	free_stack_algo(copia_a);
	free_stack_algo(copia_b);
	return (ret);
}
