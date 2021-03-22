/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_print_arrint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:21:30 by dmalori           #+#    #+#             */
/*   Updated: 2021/03/22 14:21:47 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_arrint(int *arr, int len, char *prefix)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_printf("%s%d ", prefix, arr[i]);
		i++;
	}
}
