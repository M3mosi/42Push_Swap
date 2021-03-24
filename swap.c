/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:53:49 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 17:09:06 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				do_sasb(t_stack *stack)
{
	int	tmp1;
	int tmp2;

	if (stack->len <= 1)
		return (0);
	tmp1 = stack->indexed[0];
	stack->indexed[0] = stack->indexed[1];
	stack->indexed[1] = tmp1;
	tmp2 = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp2;
	return (1);
}

int				do_ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len <= 1 || stack_b->len <= 1)
		return (0);
	do_sasb(stack_a);
	do_sasb(stack_b);
	return (1);
}

void			shift_stack(t_stack *stack, int mod)
{
	int tmp1;
	int tmp2;
	int i;

	i = 0;
	if (mod)
	{
		tmp1 = stack->stack[0];
		tmp2 = stack->indexed[0];
	}
	while (i < stack->len)
	{
		stack->stack[i - 1] = stack->stack[i];
		stack->indexed[i - 1] = stack->indexed[i];
		i++;
	}
	if (mod)
	{
		stack->stack[stack->len - 1] = tmp1;
		stack->indexed[stack->len - 1] = tmp2;
		return ;
	}
	stack->stack[stack->len - 1] = 0;
	stack->indexed[stack->len - 1] = 0;
	stack->len -= 1;
}

void			shift_rev_stack(t_stack *stack, int mod)
{
	int tmp1;
	int tmp2;
	int i;

	i = stack->len;
	if (mod == 1)
	{
		tmp1 = stack->stack[stack->len - 1];
		tmp2 = stack->indexed[stack->len - 1];
		i = stack->len - 1;
	}
	else
		stack->len += 1;
	while (i >= 0)
	{
		stack->stack[i + 1] = stack->stack[i];
		stack->indexed[i + 1] = stack->indexed[i];
		i--;
	}
	if (mod == 1)
	{
		stack->stack[0] = tmp1;
		stack->indexed[0] = tmp2;
	}
}

int				do_push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 0)
		return (0);
	shift_rev_stack(stack_b, 0);
	stack_b->stack[0] = stack_a->stack[0];
	stack_b->indexed[0] = stack_a->indexed[0];
	shift_stack(stack_a, 0);
	return (1);
}
