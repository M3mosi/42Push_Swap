/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 12:54:15 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			indexing(t_stack *stack, int j)
{
	int		*used;
	int		*out;
	int		i;
	int		k;
	int		min;

	i = 0;
	used = malloc(stack->len * sizeof(int));
	ft_init_array_num(used, stack->len, 0);
	while (i < stack->len)
	{
		min = MAX_INT;
		k = 0;
		while (k < stack->len)
		{
			if (used[k] == 0 && stack->indexed[k] <= min)
				min = stack->indexed[k];
			k++;
		}
		k = 0;
		while (k < stack->len)
		{
			if (stack->indexed[k] == min && used[k] == 0)
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
	if (!(stack.stack = malloc(len * sizeof(int *))))
		return (stack);
	if (!(stack.indexed = malloc(len * sizeof(int *))))
		return (stack);
	ft_init_array_num(stack.stack, len, 0);
	ft_init_array_num(stack.indexed, len, 0);
	stack.len = 0;
	indexing(&stack, 1);
	return (stack);
}

t_stack			parsing(t_stack stack_a, char **argv, int argc)
{
	flag_taker(&stack_a, argc, argv);
	stack_a = parse_multi(argc, argv, stack_a);
	if (stack_a.error == 1)
	{
		ft_printf(FRED"ERRORE\n"NONE);
		free(stack_a.stack);
		exit(0);
	}
	if (stack_a.file)
		ft_get_next_line(0, &stack_a.filepath);
	else
		stack_a.filepath = 0;
	stack_a.indexed = malloc(stack_a.len * sizeof(int));
	ft_init_array_num(stack_a.indexed, stack_a.len, 0);
	indexing(&stack_a, 1);
	return (stack_a);
}

int				main(int argc, char **argv, char **env)
{
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a = parsing(stack_a, argv, argc);
	stack_b = init_stack(stack_b, stack_a.len);
	ft_print_arrint(stack_a.stack, stack_a.len, FRED);
	ft_print_arrint(stack_a.stack, stack_a.len, FPURPLE);
	final_algo_start(&stack_a, &stack_b);
	free(stack_a.stack);
	free(stack_a.indexed);
	free(stack_b.stack);
	free(stack_b.indexed);
	free(stack_a.moves);
	return (0);
}
