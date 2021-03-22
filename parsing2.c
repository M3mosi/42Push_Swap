/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgiovo <sgiovo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:31:30 by sgiovo            #+#    #+#             */
/*   Updated: 2021/03/22 17:39:26 by sgiovo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int     mparse_helper(char **argv, char **split, int  i, int *out)
{
    int		k;
    int     j;

    j = 0; 
    k = 0;
    while (argv[++k])
    {
    	split = ft_split(argv[k], ' ');
    	i = -1;
    	while (split[++i])
    	{
    		if (ft_strnbr(split[i]))
    			out[j++] = ft_atoi(split[i]);
    		else if (!is_a_flag(split[i]))
    		{
    			ft_printf("errore di formato!! |%s|\n", split[i]);
    			exit(0);
    		}	
    	}
    	ft_free_matrix((void **)split, ft_matrix_len(split));
    }
    return j;
}