/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 15:53:49 by forsili           #+#    #+#             */
/*   Updated: 2021/03/23 11:24:11 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			do_sasb(t_stack *stack)
{
	int	tmp1;
	int tmp2;

	tmp1 = stack->indexed[0];
	stack->indexed[0] = stack->indexed[1];
	stack->indexed[1] = tmp1;
	tmp1 = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = tmp1;
}

void			do_ss(t_stack *stack_a, t_stack *stack_b)
{
	do_sasb(stack_a);
	do_sasb(stack_b);
}

void			shift_stack_mod0(t_stack *stack)
{
	int	*out;
	int	*ind;
	int i;
	int k;
	int len;

	i = 0;
	k = 1;
	out = ft_calloc(stack->len + 1, sizeof(int));
	ind = ft_calloc(stack->len + 1, sizeof(int));
	while (k < stack->len)
	{
		out[i] = stack->stack[k];
		ind[i] = stack->indexed[k];
		i++;
		k++;
	}
	stack->len -= 1;
	free(stack->stack);
	free(stack->indexed);
	stack->stack = out;
	stack->indexed = ind;
}

void			shift_stack_mod1(t_stack *stack)
{
	int	*out;
	int	*ind;
	int i;
	int k;
	int len;

	i = 0;
	k = 1;
	out = ft_calloc(stack->len + 1, sizeof(int));
	ind = ft_calloc(stack->len + 1, sizeof(int));
	out[stack->len - 1] = stack->stack[0];
	ind[stack->len - 1] = stack->indexed[0];
	while (k < stack->len)
	{
		out[i] = stack->stack[k];
		ind[i] = stack->indexed[k];
		i++;
		k++;
	}
	free(stack->stack);
	free(stack->indexed);
	stack->stack = out;
	stack->indexed = ind;
}

void			shift_stack(t_stack *stack, int mod)
{
	if (mod)
		shift_stack_mod1(stack);
	else
		shift_stack_mod0(stack);
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

void			do_push(t_stack *stack_a, t_stack *stack_b)
{
	shift_rev_stack(stack_b, 0);
	stack_b->stack[0] = stack_a->stack[0];
	stack_b->indexed[0] = stack_a->indexed[0];
	shift_stack(stack_a, 0);
}
