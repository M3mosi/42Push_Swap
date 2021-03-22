/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:57:00 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 19:27:11 by dmalori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int				check_double(int *arr, int len)
{
	int i;
	int k;

	i = 0;
	while (i < len)
	{
		k = i + 1;
		while (k < len)
		{
			if (arr[i] == arr[k])
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

int				is_a_flag(char *str)
{
	if (!ft_strcmp(str, "-v") && ft_strlen(str) == 2)
		return (1);
	else if (!ft_strcmp(str, "-c") && ft_strlen(str) == 2)
		return (1);
	else if (!ft_strcmp(str, "-file") && ft_strlen(str) == 5)
		return (1);
	return (0);
}

int				count_for_alloc(int argc, char **argv)
{
	int		i;
	int		k;
	char	**split;

	i = 1;
	k = 0;
	split = NULL;
	while (i < argc && !is_a_flag(argv[i]))
	{
		split = ft_split(argv[i], ' ');
		k += ft_matrix_len(split);
		ft_free_matrix(split, ft_matrix_len(split));
		i++;
	}
	return (k + 1);
}

t_stack			parse_multi(int argc, char **argv, t_stack stack, int j)
{
	int		i;
	int		*out;
	int		r_argc;
	char	**split;

	r_argc = argc - stack.visual - stack.file - stack.color;
	if (!(out = malloc(count_for_alloc(argc, argv) * sizeof(int))))
		exit(0);
	j = mparse_helper(argv, split, i, out);
	stack.len = j;
	stack.stack = out;
	stack.error = check_double(stack.stack, stack.len);
	return (stack);
}

void			flag_taker(t_stack *stack, int argc, char **argv)
{
	int		i;

	stack->error = 0;
	stack->file = 0;
	stack->visual = 0;
	stack->color = 0;
	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-v") && ft_strlen(argv[i]) == 2)
			stack->visual++;
		else if (!ft_strcmp(argv[i], "-c") && ft_strlen(argv[i]) == 2)
			stack->color++;
		else if (!ft_strcmp(argv[i], "-file") && ft_strlen(argv[i]) == 5)
			stack->file++;
		i++;
	}
}
