#include "pushswap.h"

void final_algo_start(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_lis	res_lis;

	res_lis.arr = ft_calloc(stack_a->len, sizeof(int));
	res_lis.len = stack_a->len;
	lis(&res_lis, stack_a);
	lis_select(&res_lis);
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
	free(res_lis.arr);
	ft_printf("MOVES PRE: %d\n", MOVES);
	final_algo(stack_a, stack_b);
	ft_print_arrint(stack_a->stack, stack_a->len, " ");
	ft_printf("MOVES TOTAL: %d\n", MOVES);
	ft_printf("ERROR: %d B-VUOTO %d\n", error(stack_a), stack_b->len);
}