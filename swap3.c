/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:39:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 12:10:36 by forsili          ###   ########.fr       */
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

void			add_move(t_stack *stack_a, char *move, int res)
{
	if (res)
		stack_a->tot_move++;
	if (!stack_a->ricorsione)
		ft_printf("%s\n", move);
}

void			error_exit(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_a->indexed);
	free(stack_b->stack);
	free(stack_b->indexed);
	if (stack_a->check_moves != NULL)
		free(stack_a->check_moves);
	write(2, "Error\n", 6);
	exit (0);
}

void			move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	int res;

	res = 0;
	if (!ft_strncmp(move, "sa", ft_strlen(move)) && ft_strlen(move) == ft_strlen("sa"))
		res = do_sasb(stack_a);
	else if (!ft_strncmp(move, "sb", ft_strlen(move)) && ft_strlen(move) == ft_strlen("sb"))
		res = do_sasb(stack_b);
	else if (!ft_strncmp(move, "ss", ft_strlen(move)) && ft_strlen(move) == ft_strlen("ss"))
		res = do_ss(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa", ft_strlen(move)) && ft_strlen(move) == ft_strlen("pa"))
		res = do_push(stack_b, stack_a);
	else if (!ft_strncmp(move, "pb", ft_strlen(move)) && ft_strlen(move) == ft_strlen("pb"))
		res = do_push(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra", ft_strlen(move)) && ft_strlen(move) == ft_strlen("ra"))
		res = rotate_one_stack(stack_a);
	else if (!ft_strncmp(move, "rb", ft_strlen(move)) && ft_strlen(move) == ft_strlen("rb"))
		res = rotate_one_stack(stack_b);
	else if (!ft_strncmp(move, "rr", ft_strlen(move)) && ft_strlen(move) == ft_strlen("rr"))
		res = rotate_two_stack(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra", ft_strlen(move)) && ft_strlen(move) == ft_strlen("rra"))
		res = rotate_rev_one_stack(stack_a);
	else if (!ft_strncmp(move, "rrb", ft_strlen(move)) && ft_strlen(move) == ft_strlen("rrb"))
		res = rotate_rev_one_stack(stack_b);
	else if (!ft_strncmp(move, "rrr", ft_strlen(move)) && ft_strlen(move) == ft_strlen("rrr"))
		res = rotate_rev_two_stack(stack_a, stack_b);
	else
		error_exit(stack_a, stack_b);
	add_move(stack_a, move, res);
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
