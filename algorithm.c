/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 21:45:49 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 12:51:09 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		print_stack(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int max;
	char s[100];
	char **out;

	i = 0;
	max = stack_a->len + stack_b->len;
	ft_printf("\e[1;1H\e[2J");
	while (i < max)
	{
		if (i < stack_a->len)
			ft_printf(FRED"%.3d|%s%*.d%s%*.d|", stack_a->indexed[i],BRED, stack_a->indexed[i],0, NONE, max +1 - stack_a->indexed[i], 0);
		else if (i < stack_b->len)
			ft_printf(FRED"%3.d %*.d%s|", 0, max + 1, 0, NONE);
		if (i < stack_b->len)
			ft_printf(FGREEN"%.3d|%s%*.d%s", stack_b->indexed[i],BGREEN, stack_b->indexed[i],0, NONE);
		//else
//			printf(FGREEN"%3.d|%s   \n", 0, NONE);
		ft_printf("\n");
		i++;
	}
	//i = 0;
	//while (i < stack_b->len)
	//{
	//	if (i < stack_b->len)
	//		printf(FGREEN"%.3d|%s%*.d%s\n", stack_b->stack[i],BGREEN, stack_b->stack[i],0, NONE);
	//	//else
	//		//printf(FGREEN"%3.d|   ", 0);
	//	i++;
	//}
	usleep(1000000);
	printf("___________________________________________________________________________________________________________________________\n");
	//scanf("%c", s);
}

int			is_ordinated(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] != (i + 1))
			return (0);
		i++;
	}
	return (1);
}

int			src_min(t_stack *stack, int min)
{
	int i;

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

char **RES = NULL;
int FIND = 3;