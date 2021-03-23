/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:39:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/23 12:34:45 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				check_empty(t_stack *stack)
{
	int i;
	int	k;

	i = 0;
	k = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] != 0)
			k++;
		i++;
	}
	return (k);
}

void			add_move(t_stack *stack_a, char *move)
{
	stack_a->tot_move++;
	//ft_printf("%s\n", move);
}

void			move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	add_move(stack_a, move);
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

void			indexing(t_stack *stack, int j)
{
	int		*used;
	int		i;
	int		k;
	int		min;

	i = 0;
	if (!(used = ft_calloc(stack->len + 1, sizeof(int))))
		exit(0);
	while (i < stack->len)
	{
		min = MAX_INT;
		k = 0;
		while (k < stack->len)
		{
			if (used[k] == 0 && stack->stack[k] <= min)
				min = stack->stack[k];
			k++;
		}
		k = 0;
		while (k < stack->len)
		{
			if (stack->stack[k] == min && used[k] == 0)
			{
				used[k] = 1;
				stack->indexed[k] = j;
				j++;
			}
			k++;
		}
		i++;
	}
	free(used);
}

t_stack			init_stack(t_stack stack, int len)
{
	if (!(stack.stack = ft_calloc(len + 1, sizeof(int))))
		exit(0);
	if (!(stack.indexed = ft_calloc(len + 1, sizeof(int))))
		exit(0);
	stack.len = 0;
	return (stack);
}
