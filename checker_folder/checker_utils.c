/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:31:26 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 11:57:36 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int				ft_ok(t_stack *stack)
{
	if (stack->len == 3 && stack->tot_move <= 3)
		return (1);
	else if (stack->len == 3)
		return (0);
	if (stack->len == 5 && stack->tot_move <= 12)
		return (1);
	else if (stack->len == 5)
		return (0);
	if (stack->len == 100 && stack->tot_move <= 700)
		return (1);
	else if (stack->len == 100)
		return (0);
	if (stack->len == 500 && stack->tot_move <= 5500)
		return (1);
	else if (stack->len == 500)
		return (0);
	return (1);
}

void			read_file(t_stack *stack_a)
{
	int fd;

	ft_printf("INSERISCI IL PATH DEL FILE\n");
	ft_get_next_line(0, &stack_a->filepath);
	fd = open(stack_a->filepath, O_RDONLY);
	stack_a->check_moves = NULL;
	if (fd < 0)
		stack_a->error = 1;
	else
		stack_a->check_moves = line_taker(fd);
	free(stack_a->filepath);
}

t_stack			init_values_checker(t_stack stack_a)
{
	stack_a.len = 0;
	stack_a.error = 0;
	stack_a.visual = 0;
	stack_a.file = 0;
	stack_a.filepath = NULL;
	stack_a.tot_move = 0;
	stack_a.check_moves = NULL;
	stack_a.rev = 0;
	stack_a.moves = NULL;
	stack_a.ricorsione = 0;
	return (stack_a);
}

void			end_checker(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->visual)
		ft_printf("\e[1;1H\e[2J");
	if (is_ordinated(stack_a) && stack_b->len == 0 && ft_ok(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free(stack_a->stack);
	free(stack_a->indexed);
	free(stack_b->stack);
	free(stack_b->indexed);
	ft_free_matrix(stack_a->check_moves, ft_matrix_len(stack_a->check_moves));
}
