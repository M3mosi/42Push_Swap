/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:51 by forsili           #+#    #+#             */
/*   Updated: 2021/03/23 12:54:34 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rotate_one_stack(t_stack *stack)
{
	if (stack->len == 0)
		return ;
	shift_stack(stack, 1);
}

void		rotate_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return ;	
	shift_stack(stack_a, 1);
	shift_stack(stack_b, 1);
}

void		rotate_rev_one_stack(t_stack *stack)
{
	if (stack->len == 0)
		return ;
	shift_rev_stack(stack, 1);
}

void		rotate_rev_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0 || stack_b->len == 0)
		return ;
	shift_rev_stack(stack_a, 1);
	shift_rev_stack(stack_b, 1);
}

