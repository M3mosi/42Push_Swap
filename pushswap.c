/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 16:31:19 by dmalori          ###   ########.fr       */
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
	used = ft_calloc(stack->len, sizeof(int));
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
	if (!(stack_a.indexed = ft_calloc(stack_a.len + 1, sizeof(int))))
		exit(0);
	indexing(&stack_a, 1);
	return (stack_a);
}

int				main(int argc, char **argv, char **env)
{
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a = parsing(stack_a, argv, argc);
	stack_b = init_stack(stack_b, stack_a.len);
	final_algo_start(&stack_a, &stack_b);
	ft_printf("\nMOVES: %d - ERROR %d - LEN B %d\n\n", stack_a.tot_move, error(&stack_a), stack_b.len);
	ft_print_arrint(stack_a.stack, stack_a.len, "");
	free(stack_a.stack);
	free(stack_a.indexed);
	free(stack_b.stack);
	free(stack_b.indexed);
	free(stack_a.moves);
	return (0);
}
