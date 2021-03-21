/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:21:34 by forsili           #+#    #+#             */
/*   Updated: 2021/03/19 15:02:45 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **matrix, char *prefix)
{
	int i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		ft_printf("%s%s\n", prefix, matrix);
		i++;
	}
}

void	ft_print_arrint(int *arr, int len, char *prefix)
{
	int		i;

	i = 0;
	while (i < len)
	{
		ft_printf("%s%d\n", prefix, arr[i]);
		i++;
	}
	
}