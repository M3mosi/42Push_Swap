/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:13:17 by forsili           #+#    #+#             */
/*   Updated: 2021/03/21 20:06:23 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int		is_all_flag(char **input, int argc)
{
	int i;
	int v;
	int c;
	int f;

	i = 2;
	v = 0;
	c = 0;
	f = 0;
	while (i < argc)
	{
		if (!ft_strncmp(input[i], "-v", ft_strlen(input[i])) && v == 0)
		{
			v++;
			i++;
		}
		else if (!ft_strncmp(input[i], "-c", ft_strlen(input[i])) && c == 0)
		{
			c++;
			i++;
		}
		else if (!ft_strncmp(input[i], "-file", ft_strlen(input[i])) && f == 0)
		{
			f++;
			i++;
		}
		else
			return (0);
	}
	return (1);
}

int		parse_input_string(char **argv, int argc, t_stack *stack_a)
{
	char	**split;
	int		i;
	int		k;

	i = 0;
	if (argc == 2 || is_all_flag(argv, argc))
	{
		split = ft_split(argv[1], ' ');
		stack_a->stack = malloc(ft_matrix_len(split) * sizeof(int));
		stack_a->len = 0;
		while (split[i])
		{
			k = 0;
			while (split[i][k])
			{
				if (!ft_isdigit(split[i][k]) || ft_atoi(split[i]) < MIN_INT ||
					ft_atoi(split[i]) > MAX_INT);
					//stack_a->error = 1;
				k++;
			}
			stack_a->stack[i] = ft_atoi(split[i]);
			stack_a->len++;
			i++;
		}
		if (argc == 3 && !ft_strncmp(argv[2], "-v", ft_strlen(argv[2])))
			stack_a->visual = 1;
		if (argc == 3 && !ft_strncmp(argv[2], "-c", ft_strlen(argv[2])))
			stack_a->color = 1;
		if (argc == 3 && !ft_strncmp(argv[2], "-file", ft_strlen(argv[2])))
			stack_a->file = 1;
		if (argc == 4 && !ft_strncmp(argv[3], "-v", ft_strlen(argv[3])))
			stack_a->visual = 1;
		if (argc == 4 && !ft_strncmp(argv[3], "-c", ft_strlen(argv[3])))
			stack_a->color = 1;
		if (argc == 4 && !ft_strncmp(argv[3], "-file", ft_strlen(argv[3])))
			stack_a->file = 1;
		if (argc == 5 && !ft_strncmp(argv[4], "-v", ft_strlen(argv[4])))
			stack_a->visual = 1;
		if (argc == 5 && !ft_strncmp(argv[4], "-c", ft_strlen(argv[4])))
			stack_a->color = 1;
		if (argc == 5 && !ft_strncmp(argv[4], "-file", ft_strlen(argv[4])))
			stack_a->file = 1;
		return (1);
	}
	else
		return (0);
}

t_stack			init_stack_a(t_stack stack)
{
	stack.len = 0;
	stack.error = 0;
	stack.visual = 0;
	stack.color = 0;
	stack.file = 0;
	return (stack);
}

int		main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	stack_a = init_stack_a(stack_a);
	if(parse_input_string(argv, argc, &stack_a) == 0)
		return (0);
	if (stack_a.error > 0)
	{
		printf("ERROR\n");
		return (0);
	}
	ft_printf("%d V%d C%d F%d E%d\n", stack_a.len, stack_a.visual, stack_a.color, stack_a.file, stack_a.error);
	ft_print_arrint(stack_a.stack, stack_a.len, "");
	return (0);
}