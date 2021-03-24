/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:45:49 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 11:37:55 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		k;
	int		max;
	int		len;

	i = 0;
	len = stack_a->len;
	if (stack_b->len > stack_a->len)
		len = stack_b->len;
	max = stack_a->len + stack_b->len;
	ft_printf("\e[1;1H\e[2J");
	ft_printf("|%s%*.d| A %s|%s B |%*.d%s|\n", BBLACK, max + 1, 0, NONE, BBLACK, max + 1, 0, NONE);
	while (i < len)
	{	
		if (i < stack_a->len)
		{
			ft_printf("|%*.d", max + 1 - stack_a->indexed[i], 0);
			k = 0;
			while (k < stack_a->indexed[i])
			{
				ft_printf("%s %s", BRED, NONE);
				k++;
			}
			ft_printf(FRED"|%.3d%s|", stack_a->indexed[i], NONE);
		}
		else if (i < stack_b->len)
			ft_printf("|%3.d%*.d%s|", 0, max + 2, 0, NONE);
		if (i < stack_b->len)
			ft_printf(FGREEN"%.3d|%s%*.d%s%*.d|", stack_b->indexed[i], BGREEN,
				stack_b->indexed[i], 0, NONE, max + 1 - stack_b->indexed[i], 0);
		else if (i < stack_a->len)
			ft_printf("    %*.d|", max + 1, 0);
		ft_printf("\n");
		i++;
	}
	ft_printf("|%s%*.d|MOV%s|%.*d%s|%*.d%s|\n", BBLACK, max + 1, 0, NONE, 3,stack_a->tot_move, BBLACK, max + 1, 0, NONE);
	usleep(500000);
}

int			is_ordinated(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->indexed[i] != (i + 1))
			return (0);
		i++;
	}
	return (1);
}

int			src_min(t_stack *stack, int min)
{
	int i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] == min)
		{
			if (i < (stack->len / 2))
				return (1);
			else
				return (-1);
		}
		i++;
	}
	return (1);
}
