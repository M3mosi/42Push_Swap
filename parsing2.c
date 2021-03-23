/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:31:30 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/23 17:57:23 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		mparse_helper(char **argv, char **split, int i, int *out)
{
	int		k;
	int		j;

	j = 0;
	k = 1;
	split = NULL;
	while (argv[k])
	{
		split = ft_split(argv[k], ' ');
		i = 0;
		while (split[i])
		{
			if (ft_strnbr(split[i]))
				out[j++] = ft_atoi(split[i]);
			else if (!is_a_flag(split[i]))
			{
				write(2, "Error\n", 6);
				exit(0);
			}
			i++;
		}
		ft_free_matrix(split, ft_matrix_len(split));
		k++;
	}
	return (j);
}
