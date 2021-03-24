/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:41:46 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/24 16:42:01 by dmalori          ###   ########.fr       */
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
