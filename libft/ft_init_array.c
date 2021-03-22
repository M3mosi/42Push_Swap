/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:47:11 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 09:51:59 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init_array_num(int *arr, int len, int n)
{
	int i;

	i = 0;
	while (i < len)
	{
		arr[i] = n;
		i++;
	}
}
