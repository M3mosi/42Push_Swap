/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:39:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/21 22:22:38 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	stack_a->tot_move++;
	stack_a->moves = ft_strjoin(&stack_a->moves, " ", 1);
	stack_a->moves = ft_strjoin(&stack_a->moves, move, 1);
	if (!ft_strncmp(move, "sa", ft_strlen(move)))
		do_sasb(stack_a);
	else if (!ft_strncmp(move, "sb", ft_strlen(move)))
		do_sasb(stack_b);
	else if (!ft_strncmp(move, "ss", ft_strlen(move)))
		do_ss(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa", ft_strlen(move)))
		do_push(stack_b, stack_a);
	else if (!ft_strncmp(move, "pb", ft_strlen(move)))
		do_push(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra", ft_strlen(move)))
		rotate_one_stack(stack_a);
	else if (!ft_strncmp(move, "rb", ft_strlen(move)))
		rotate_one_stack(stack_b);
	else if (!ft_strncmp(move, "rr", ft_strlen(move)))
		rotate_two_stack(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra", ft_strlen(move)))
		rotate_rev_one_stack(stack_a);
	else if (!ft_strncmp(move, "rrb", ft_strlen(move)))
		rotate_rev_one_stack(stack_b);
	else if (!ft_strncmp(move, "rrr", ft_strlen(move)))
		rotate_rev_two_stack(stack_a, stack_b);
	if (stack_a->visual == 1)
		print_stack(stack_a, stack_b);
}