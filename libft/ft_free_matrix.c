/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 22:17:02 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 14:19:58 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_matrix(void **matrix, int len)
{
	int i;

	i = 0;
	if (!matrix)
		return ;
	while (i < len)
	{
		ft_memset(matrix[i], 0, ft_strlen(matrix[i]));
		free(matrix[i]);
		i++;
	}
	ft_memset(matrix[i], 0, ft_strlen(matrix[i]));
	free(matrix[i]);
	free(matrix);
}
