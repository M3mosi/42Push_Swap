/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:51 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 16:29:06 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		rotate_one_stack(t_stack *stack)
{
	if (stack->len <= 1)
		return (0);
	shift_stack(stack, 1);
	return (1);
}

int		rotate_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 1 || stack_b->len <= 1)
		return (0);	
	shift_stack(stack_a, 1);
	shift_stack(stack_b, 1);
	return (1);
}

int		rotate_rev_one_stack(t_stack *stack)
{
	if (stack->len <= 1)
		return (0);
	shift_rev_stack(stack, 1);
	return (1);
}

int		rotate_rev_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 1 || stack_b->len <= 1)
		return (0);
	shift_rev_stack(stack_a, 1);
	shift_rev_stack(stack_b, 1);
	return (1);
}

t_stack			init_stack(t_stack stack, int len)
{
	if (!(stack.stack = ft_calloc(len + 1, sizeof(int))))
		exit(0);
	if (!(stack.indexed = ft_calloc(len + 1, sizeof(int))))
		exit(0);
	stack.len = 0;
	stack.error = 0;
	stack.color = 0;
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
