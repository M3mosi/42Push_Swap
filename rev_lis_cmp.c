/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_lis_cmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 12:04:01 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/24 16:25:37 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void		rev_lis(t_lis *lis, t_stack *s)
{
	int	i;
	int	j;

	lis->max = 0;
	i = lis->len -1;
	while (i >= 0)
	{
		j = lis->len;
		while (j > i)
		{
			if (s->indexed[i] > s->indexed[j] && lis->arr[i] < lis->arr[j] + 1)
				lis->arr[i] = lis->arr[j] + 1;
			j--;
		}
		i--;
	}
	i = 0;
	while (i < lis->len)
	{
		lis->max = lis->max > lis->arr[i] ? lis->max : lis->arr[i];
		i++;
	}
}


void		rev_lis_select(t_lis *lis)
{
	int i;

	i = 0;
	while (i < lis->len)
	{
		if (lis->arr[i] == lis->max && lis->max > 0)
		{
			lis->max--;
			i++;
			continue;
		}
		lis->arr[i] = 0;
		i++;
	}
}
