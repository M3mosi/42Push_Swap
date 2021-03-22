/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:31:26 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 17:48:02 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		read_file(t_stack *stack_a)
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
}
