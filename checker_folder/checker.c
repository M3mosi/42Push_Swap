/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forsili <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:13:17 by forsili           #+#    #+#             */
/*   Updated: 2021/03/24 12:01:03 by forsili          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char			**line_taker(int fd)
{
	char	**moves;
	char	*tmpline;
	char	*line;
	int		res;

	line = ft_strdup("");
	while ((res = ft_get_next_line(fd, &tmpline)) > 0)
	{
		line = ft_strjoin(line, tmpline, 1);
		line = ft_strjoin(line, "\n", 1);
		free(tmpline);
	}
	free(tmpline);
	moves = ft_split(line, '\n');
	free(line);
	return (moves);
}

t_stack			parsing_checker(t_stack stack_a, char **argv, int argc)
{
	stack_a.len = 0;
	stack_a.error = 0;
	stack_a.color = 0;
	stack_a.visual = 0;
	stack_a.file = 0;
	stack_a.filepath = NULL;
	stack_a.tot_move = 0;
	stack_a.check_moves = NULL;
	stack_a.rev = 0;
	stack_a.moves = NULL;
	stack_a.ricorsione = 0;
	flag_taker(&stack_a, argc, argv);
	if (stack_a.file == 0 && !isatty(fileno(stdin)))
		stack_a.check_moves = line_taker(0);
	else
		stack_a.check_moves = NULL;
	stack_a = parse_multi(argc, argv, stack_a, 0);
	if (stack_a.file)
		read_file(&stack_a);
	if (stack_a.error == 1)
	{
		write(2, "Error\n", 6);
		free(stack_a.stack);
		ft_free_matrix(stack_a.check_moves, ft_matrix_len(stack_a.check_moves));
		exit(0);
	}
	else
		stack_a.filepath = 0;
	if (!(stack_a.indexed = ft_calloc(stack_a.len + 1, sizeof(int))))
		exit(0);
	indexing(&stack_a, 1);
	return (stack_a);
}

void			ordina_array(t_stack *stack_a, t_stack *stack_b)
{
	int		i;

	i = 0;
	if (stack_a->visual == 1)
		print_stack(stack_a, stack_b);
	while (stack_a->check_moves[i])
	{
		move(stack_a, stack_b, stack_a->check_moves[i]);
		i++;
	}
}

void			read_line(t_stack *stack_a, t_stack *stack_b)
{
	char *cmd;

	if (stack_a->visual == 1)
		print_stack(stack_a, stack_b);
	while (1)
	{
		ft_get_next_line(0, &cmd);
		move(stack_a, stack_b, cmd);
		if (!ft_strncmp(cmd, "stop", ft_strlen("stop")) &&
			ft_strlen(cmd) == ft_strlen("stop"))
		{
			free(cmd);
			return ;
		}
		free(cmd);
		if (is_ordinated(stack_a) && stack_b->len == 0)
			break ;
	}
}

int				main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	if (argc == 1)
		return (0);
	ft_memset(&stack_a, 0, sizeof(t_stack));
	ft_memset(&stack_b, 0, sizeof(t_stack));
	stack_a = parsing_checker(stack_a, argv, argc);
	stack_a.ricorsione = 1;
	if (is_ordinated(&stack_a) && stack_b.len == 0)
	{
		free(stack_a.stack);
		free(stack_a.indexed);
		ft_printf(FGREEN"OK\n"NONE);
		exit(0);
	}
	stack_b = init_stack(stack_b, stack_a.len);
	if (stack_a.file == 1 || stack_a.check_moves != NULL)
		ordina_array(&stack_a, &stack_b);
	else
		read_line(&stack_a, &stack_b);
	//ft_printf("\e[1;1H\e[2J");
	if (is_ordinated(&stack_a) && stack_b.len == 0)
		ft_printf(FGREEN"OK\n"NONE);
	else
		ft_printf(FRED"KO\n"NONE);
	free(stack_a.stack);
	free(stack_a.indexed);
	free(stack_b.stack);
	free(stack_b.indexed);
	ft_free_matrix(stack_a.check_moves, ft_matrix_len(stack_a.check_moves));
	return (0);
}
