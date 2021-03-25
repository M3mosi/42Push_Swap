/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:17:02 by forsili           #+#    #+#             */
/*   Updated: 2021/03/25 11:48:24 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(char **matrix, int len)
{
	int i;

	i = 0;
	if (!matrix)
		return ;
	while (i < len)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
