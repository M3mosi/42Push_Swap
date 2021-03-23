/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 17:58:51 by forsili           #+#    #+#             */
/*   Updated: 2021/03/23 11:24:35 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rotate_one_stack(t_stack *stack)
{
	shift_stack(stack, 1);
}

void		rotate_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	shift_stack(stack_a, 1);
	shift_stack(stack_b, 1);
}

void		rotate_rev_one_stack(t_stack *stack)
{
	shift_rev_stack(stack, 1);
}

void		rotate_rev_two_stack(t_stack *stack_a, t_stack *stack_b)
{
	shift_rev_stack(stack_a, 1);
	shift_rev_stack(stack_b, 1);
}

char		**define_moves(void)
{
	char	**out;

	if (!(out = malloc(MOVES_SIZE)))
		exit(0);
	out[0] = ft_strdup("sa");
	out[1] = ft_strdup("sb");
	out[2] = ft_strdup("ss");
	out[3] = ft_strdup("pa");
	out[4] = ft_strdup("pb");
	out[5] = ft_strdup("ra");
	out[6] = ft_strdup("rb");
	out[7] = ft_strdup("rr");
	out[8] = ft_strdup("rra");
	out[9] = ft_strdup("rrb");
	out[10] = ft_strdup("rrr");
	return (out);
}
