/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_lis_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:04:01 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/25 11:46:29 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			indexing2(t_stack *stack, int j, int k, int i)
{
	int		*used;
	int		min;

	i = -1;
	if (!(used = ft_calloc(stack->len + 1, sizeof(int))))
		exit(0);
	while (++i < stack->len)
	{
		min = MAX_INT;
		k = -1;
		while (++k < stack->len)
			if (used[k] == 0 && stack->stack[k] <= min)
				min = stack->stack[k];
		k = -1;
		while (++k < stack->len)
		{
			if (stack->stack[k] == min && used[k] == 0)
			{
				used[k] = 1;
				stack->indexed[k] = j;
				j++;
			}
		}
	}
	free(used);
}

void			indexing(t_stack *stack, int j)
{
	indexing2(stack, j, 0, 0);
}

t_stack			init_stack(t_stack stack, int len)
{
	if (!(stack.stack = ft_calloc(len + 1, sizeof(int))))
		exit(0);
	if (!(stack.indexed = ft_calloc(len + 1, sizeof(int))))
		exit(0);
	stack.len = 0;
	stack.error = 0;
	stack.visual = 0;
	stack.file = 0;
	stack.filepath = NULL;
	stack.tot_move = 0;
	stack.check_moves = NULL;
	stack.rev = 0;
	stack.moves = NULL;
	stack.ricorsione = 0;
	return (stack);
}
