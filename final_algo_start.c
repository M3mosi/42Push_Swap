/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:43:11 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 14:32:38 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	final_algo_start(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_lis	res_lis;

	res_lis.arr = malloc(stack_a->len * sizeof(int));
	ft_init_array_num(res_lis.arr, stack_a->len, 1);
	res_lis.len = stack_a->len;
	lis(&res_lis, stack_a);
	lis_select(&res_lis);
	i = 0;
	stack_a->tot_move = 0;
	stack_a->moves = ft_strdup("");
	while (i < res_lis.len)
	{
		if (res_lis.arr[i] == 0)
			move(stack_a, stack_b, "pb");
		else
			move(stack_a, stack_b, "ra");
		i++;
	}
	free(res_lis.arr);
	final_algo(stack_a, stack_b);
}
