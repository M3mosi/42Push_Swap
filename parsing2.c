/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:31:30 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/24 15:11:17 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int		mparse_helper(char **argv, int r_argc, int i, int *out)
{
	int		k;
	int		j;
	char	**split;

	j = 0;
	k = 1;
	split = NULL;
	while (k < r_argc)
	{
		split = ft_split(argv[k], ' ');
		i = 0;
		while (split[i])
		{
			if (ft_strnbr(split[i]) && ft_atoi(split[i]) < MAX_INT &&
			ft_atoi(split[i]) > MIN_INT && ft_strlen(split[i]) < 12)
				out[j++] = (int)ft_atoi(split[i]);
			else if (!is_a_flag(split[i]) || !ft_strnbr(split[i]))
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
