/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simonegiovo <simonegiovo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:32:43 by forsili           #+#    #+#             */
/*   Updated: 2021/03/21 21:02:34 by simonegiovo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void			indexing(t_stack *stack, int j)
{
	char	*used;
	int		*out;
	int 	i;
	int		k;
	int		min;

	i = 0;
	used = ft_calloc(500, sizeof(int));
	while (i < stack->len)
	{
		min = MAX_INT;
		k = -1;
		while (++k < stack->len)
			if (used[k] == 0 && stack->stack[k] <= min)
				min = stack->stack[k];
		k = -1;
		while (++k < stack->len)
		{
			if (stack->stack[k] == min && used[k] == 0)
			{
				used[k] = 1;
				stack->indexed[k] = j;
				j++;
			}
		}
		i++;
	}
	free(used);
}

t_stack			parse(int argc, char **argv, t_stack stack)
{
	int		i;
	char	**tmp;
	int		*out;

	//ft_printf("ciao!\n");
	tmp = ft_split(argv[1], ' ');
	if (!(out = malloc(ft_matrix_len(tmp) * sizeof(int))))
		return (stack);
	i = 0;
	while (tmp[i])
	{
		if(ft_strdigit(tmp[i]))
			out[i] = ft_atoi(tmp[i]);
		else
		{
			ft_printf("errore di formato!!\n");
			exit(0);
		}
		i++;
	}
	stack.len = i;
	ft_free_matrix(tmp, ft_matrix_len(tmp));
	stack.stack = out;
	return (stack);
}

t_stack			parse_multi(int argc, char **argv, t_stack stack)
{
	int		i;
	int		*out;
	int 	r_argc;

	r_argc = argc - stack.visual - stack.file - stack.color;
	if (!(out = malloc((r_argc) * sizeof(int))))
		return (stack);
	i = 1;
	while (i <= r_argc)
	{
		if(ft_strdigit(argv[i]))
			out[i - 1] = ft_atoi(argv[i]);
		else
		{
			ft_printf("errore di formato1!!\n");
			exit(0);
		}
		i++;
	}
	stack.len = i - 1;
	stack.stack = out;
	return (stack);
}

t_stack			init_stack(t_stack stack, int len)
{
	if (!(stack.stack = ft_calloc(len, sizeof(int *))))
		return (stack);
	if (!(stack.indexed = ft_calloc(len, sizeof(int *))))
		return (stack);
	stack.len = 0;
	
	indexing(&stack, 1);
	return (stack);
}

void			flag_taker(t_stack *stack,int argc,char **argv)
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
		else if(!ft_strcmp(argv[i], "-c") && ft_strlen(argv[i]) == 2)
			stack->color++;
		else if(!ft_strcmp(argv[i], "-file") && ft_strlen(argv[i]) == 5 )
			stack->file++;
		i++;
	}
}

int				main(int argc, char **argv, char **env)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int 		r_argc;
	char		*m;

	m = malloc(300);
	flag_taker(&stack_a, argc, argv);
	r_argc = argc - stack_a.visual - stack_a.file - stack_a.color;
	if (r_argc == 2 && !stack_a.file)
		stack_a = parse(argc, argv, stack_a);
	else if (stack_a.file)
	{
		ft_printf("BISOGNA ANCORA PARSARE IL FILE!!!\n");
		exit (0);
	}
	else if (r_argc > 2)
		stack_a = parse_multi(argc, argv, stack_a);
	stack_b = init_stack(stack_b, stack_a.len);
	stack_a.indexed = ft_calloc(stack_a.len, sizeof(int));
	indexing(&stack_a , 1);
	ft_print_arrint(stack_a.stack, stack_a.len, FRED);
	ft_print_arrint(stack_a.indexed, stack_a.len, FPURPLE);
	//final_algo_start(&stack_a, &stack_b);
	return (0);
}