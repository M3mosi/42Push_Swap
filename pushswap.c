/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 17:30:48 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack			parsing(t_stack stack_a, char **argv, int argc)
{
	flag_taker(&stack_a, argc, argv);
	stack_a = parse_multi(argc, argv, stack_a, 0);
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
	ft_printf("%s\n", stack_a.moves);
	free(stack_a.stack);
	free(stack_a.indexed);
	free(stack_b.stack);
	free(stack_b.indexed);
	free(stack_a.moves);
	return (0);
}
