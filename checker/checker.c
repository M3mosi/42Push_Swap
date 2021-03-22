/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:13:17 by forsili           #+#    #+#             */
/*   Updated: 2021/03/22 14:53:59 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char			**line_taker(int fd)
{
	int i;
	char	**moves;
	char	*tmpline;

	ft_get_next_line(fd, &tmpline);
	moves = ft_split(tmpline, ' ');
	return (moves);
}

t_stack			parsing_checker(t_stack stack_a, char **argv, int argc)
{
	char	**moves;
	int		fd;

	flag_taker(&stack_a, argc, argv);
	if (stack_a.file == 0 &&  !isatty(fileno(stdin)))
		stack_a.check_moves = line_taker(0);
	stack_a = parse_multi(argc, argv, stack_a);
	if (stack_a.file)
	{
		ft_printf("INSERISCI IL PATH DEL FILE\n");
		ft_get_next_line(0, &stack_a.filepath);
		fd = open(stack_a.filepath, O_RDONLY);
		if (fd < 0)
			stack_a.error = 1;
		//else
			//stack_a.check_moves = line_taker(fd);
	}
	if (stack_a.error == 1)
	{
		ft_printf(FRED"ERRORE\n"NONE);
		free(stack_a.stack);	
		exit(0);
	}
	else
		stack_a.filepath = 0;
	stack_a.indexed = ft_calloc(stack_a.len, sizeof(int));
	indexing(&stack_a , 1);
	return (stack_a);
}

void	ordina_array(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	char	*cmd;

	i = 0;
	while (stack_a->check_moves[i])
	{
		cmd = ft_strtrim(&stack_a->check_moves[i], " ", 0);
		move(stack_a, stack_b, stack_a->check_moves[i]);
		free(cmd);
		i++;
	}
}

void	read_line(t_stack *stack_a, t_stack *stack_b)
{
	char *cmd;

	while (1)
	{
		ft_get_next_line(0, &cmd);
		move(stack_a, stack_b, cmd);
		free(cmd);
		if (is_ordinated(stack_a) && stack_b->len == 0)
			break ;
	}
}

int		main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;
	char	*file;

	stack_a = parsing_checker(stack_a, argv, argc);
	stack_b = init_stack(stack_b, stack_a.len);
	if (stack_a.file == 1 || stack_a.check_moves != NULL)
	{
		ordina_array(&stack_a, &stack_b);
	}
	else
	{
		read_line(&stack_a, &stack_b);
	}
	ft_printf("\e[1;1H\e[2J");
	if (is_ordinated(&stack_a) && stack_b.len == 0)
		ft_printf(FGREEN"OK\n"NONE);
	else
		ft_printf(FRED"KO\n"NONE);
	return (0);
}