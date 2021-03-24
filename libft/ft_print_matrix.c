/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:21:34 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 11:01:33 by forsili          ###   ########.fr       */
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
		ft_printf("%s|%s|\n", prefix, matrix[i]);
		i++;
	}
}
