/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:51 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 17:28:13 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		rotate_one_stack(t_stack *stack)
{
	if (stack->len <= 1)
		return (1);
	shift_stack(stack, 1, 0);
	return (1);
}

int		rotate_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 1 || stack_b->len <= 1)
		return (1);
	shift_stack(stack_a, 1, 0);
	shift_stack(stack_b, 1, 0);
	return (1);
}

int		rotate_rev_one_stack(t_stack *stack)
{
	if (stack->len <= 1)
		return (1);
	shift_rev_stack(stack, 1);
	return (1);
}

int		rotate_rev_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 1 || stack_b->len <= 1)
		return (1);
	shift_rev_stack(stack_a, 1);
	shift_rev_stack(stack_b, 1);
	return (1);
}
