/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_algo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 17:13:03 by simonegiovo       #+#    #+#             */
/*   Updated: 2021/03/21 17:55:45 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"



void    lis(t_lis *lis, t_stack *s)
{
    int i;
    int j;
    
    // DA MODIFICARE
    for (int i = 0; i < lis->len; i++)
        lis->arr[i] = 1;

    lis->max = 0;
    i = 0;
    while(++i < lis->len)
    {
        j = -1;
        while(++j < i)
            if(s->indexed[i] > s->indexed[j] && lis->arr[i] < lis->arr[j] + 1)
                lis->arr[i] = lis->arr[j] + 1;
    }
    i = -1;
    while(++i < lis->len)
        lis->max = lis->max > lis->arr[i] ? lis->max : lis->arr[i];
}

void    lis_select(t_lis *lis)
{
    int i;

    i = lis->len + 1;
    while (--i > 0)
    {
        if (lis->arr[i] == lis->max && lis->max > 0)
        {
            lis->max--;
            continue;
        }
        lis->arr[i] = 0;
    }
}

int     calc_dir(int *arr, t_stack *stack, int n)
{
    int i;

    i = 0;
    while (i < stack->len)
        if (arr[i] == n)
        {
            if (i > stack->len / 2)
                return (2);
            return (1);
        }
}

int     calc_dist(int *arr, t_stack *stack, int n)
{
    int i;

    i = 0;
    while (i < stack->len)
        if (arr[i] == n)
        {
            if (i > stack->len / 2)
                return (stack->len - i);
            return (i);
        }   
}
