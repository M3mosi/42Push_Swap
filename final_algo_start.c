#include "pushswap.h"

void final_algo_start(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_lis	res_lis;

	res_lis.arr = ft_calloc(stack_a->len, sizeof(int));
	res_lis.len = stack_a->len;
	lis(&res_lis, stack_a);

	lis_select(&res_lis);

	for (int i = 0; i < res_lis.len; i++)
		ft_printf("%d ", res_lis.arr[i]);
	ft_printf("\n");

	i = 0;
	MOVES = 0;
	while (i < res_lis.len)
	{
		if (res_lis.arr[i] == 0)
		{
			move(stack_a, stack_b, "pb");
			MOVES++;
		}
		else
		{
			move(stack_a, stack_b, "ra");
			MOVES++;
		}
		i++;
	}

	ft_print_arrint(stack_a->indexed, stack_a->len, "A-");
	ft_printf("\n");
	ft_print_arrint(stack_b->indexed, stack_b->len, "B-");
	ft_printf("\n");

	ft_printf("MOVES: %d\n", MOVES);
	final_algo(stack_a, stack_b);
	ft_print_arrint(stack_a->indexed, stack_a->len, "A-");
	ft_printf("\n");
	ft_print_arrint(stack_b->indexed, stack_b->len, "B-");
	ft_printf("\n");
	ft_printf("MOVES: %d\n", MOVES);
}