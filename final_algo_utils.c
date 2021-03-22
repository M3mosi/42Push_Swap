/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:13:03 by simonegiovo       #+#    #+#             */
/*   Updated: 2021/03/22 17:10:55 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		lis(t_lis *lis, t_stack *s)
{
	int i;
	int j;

	lis->max = 0;
	i = 1;
	while (i < lis->len)
	{
		j = 0;
		while (j < i)
		{
			if (s->indexed[i] > s->indexed[j] && lis->arr[i] < lis->arr[j] + 1)
				lis->arr[i] = lis->arr[j] + 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < lis->len)
	{
		lis->max = lis->max > lis->arr[i] ? lis->max : lis->arr[i];
		i++;
	}
}

void		lis_select(t_lis *lis)
{
	int i;

	i = lis->len;
	while (--i >= 0)
	{
		if (lis->arr[i] == lis->max && lis->max > 0)
		{
			lis->max--;
			continue;
		}
		lis->arr[i] = 0;
	}
}

int			calc_dir(t_stack *s, int n)
{
	int i;

	i = 0;
	while (i < s->len)
	{
		if (s->stack[i] == n)
		{
			if (i > (s->len / 2))
			{
				return (2);
			}
			return (1);
		}
		i++;
	}
	return (-1);
}

int			calc_dist(t_stack *s, int n)
{
	int i;

	i = 0;
	while (i < s->len)
	{
		if (s->stack[i] == n)
		{
			if (i > s->len / 2)
			{
				return (s->len - i);
			}
			return (i);
		}
		i++;
	}
	return (-1);
}
