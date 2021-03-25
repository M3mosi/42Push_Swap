/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 18:39:44 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 11:46:21 by forsili          ###   ########.fr       */
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
	exit(0);
}

int				move2(t_stack *stack_a, t_stack *stack_b, char *move, int res)
{
	if (!ft_strncmp(move, "ra", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("ra"))
		res = rotate_one_stack(stack_a);
	else if (!ft_strncmp(move, "rb", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("rb"))
		res = rotate_one_stack(stack_b);
	else if (!ft_strncmp(move, "rr", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("rr"))
		res = rotate_two_stack(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("rra"))
		res = rotate_rev_one_stack(stack_a);
	else if (!ft_strncmp(move, "rrb", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("rrb"))
		res = rotate_rev_one_stack(stack_b);
	else if (!ft_strncmp(move, "rrr", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("rrr"))
		res = rotate_rev_two_stack(stack_a, stack_b);
	return (res);
}

void			move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	int res;

	res = 0;
	if (!ft_strncmp(move, "sa", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("sa"))
		res = do_sasb(stack_a);
	else if (!ft_strncmp(move, "sb", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("sb"))
		res = do_sasb(stack_b);
	else if (!ft_strncmp(move, "ss", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("ss"))
		res = do_ss(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("pa"))
		res = do_push(stack_b, stack_a);
	else if (!ft_strncmp(move, "pb", ft_strlen(move)) &&
		ft_strlen(move) == ft_strlen("pb"))
		res = do_push(stack_a, stack_b);
	else if (res == 0)
		res = move2(stack_a, stack_b, move, res);
	else
		error_exit(stack_a, stack_b);
	add_move(stack_a, move, res);
	if (stack_a->visual == 1)
		print_stack(stack_a, stack_b);
}
