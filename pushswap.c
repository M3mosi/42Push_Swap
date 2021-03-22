/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 15:06:31 by dmalori          ###   ########.fr       */
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
				//stack->indexed[k] = j;
				j++;
			}
			k++;
		}
		i++;
	}
	free(used);
}

void			init_stack(t_stack *stack, int len)
{
	stack->len = 0;
	stack->stack = ft_calloc(len, sizeof(int));
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
	return (stack_a);
}

int				main(int argc, char **argv, char **env)
{
	t_stack		stack_a;
	t_stack		stack_b;

	stack_a = parsing(stack_a, argv, argc);
	init_stack(&stack_b, stack_a.len);
	ft_printf("\n");
	ft_print_arrint(stack_b.stack, stack_b.len, FRED);
	final_algo_start(&stack_a, &stack_b);
	ft_printf("\n\n");
	ft_print_arrint(stack_a.stack, stack_a.len, FRED);
	ft_printf("\nERROR %d\n\n", error(&stack_a));
	ft_printf("\n\n%s\n", stack_a.moves);
	free(stack_a.stack);
	free(stack_b.stack);
	free(stack_a.moves);
	return (0);
}
