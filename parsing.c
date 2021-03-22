/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmalori <dmalori@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 21:57:00 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 16:30:18 by dmalori          ###   ########.fr       */
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
	while (i < argc && !is_a_flag(argv[i]))
	{
		split = ft_split(argv[i], ' ');
		k += ft_matrix_len(split);
		ft_free_matrix((void **)split, ft_matrix_len(split));
		i++;
	}
	ft_printf("LEN MATRIX %d\n\n", k);
	return (k + 1);
}

t_stack			parse_multi(int argc, char **argv, t_stack stack)
{
	int		i;
	int		k;
	int		j;
	int		*out;
	int		r_argc;
	char	**split;

	r_argc = argc - stack.visual - stack.file - stack.color;
	if (!(out = malloc(count_for_alloc(argc, argv) * sizeof(int))))
		exit(0);
	k = 1;
	j = 0;
	while (argv[k])
	{
		split = ft_split(argv[k], ' ');
		i = 0;
		while (split[i])
		{
			if (ft_strnbr(split[i]))
			{
				out[j] = ft_atoi(split[i]);
				j++;
			}
			else if (!is_a_flag(split[i]))
			{
				ft_printf("errore di formato!! |%s|\n", split[i]);
				exit(0);
			}
			i++;
		}
		ft_free_matrix((void **)split, ft_matrix_len(split));
		k++;
	}
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
