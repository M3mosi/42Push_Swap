#include "pushswap.h"

void final_algo_start(t_stack *stack_a, t_stack *stack_b)
{
	t_lis res_lis;

	res_lis.arr = ft_calloc(stack_a->len, sizeof(int));
	res_lis.len = stack_a->len;
	lis(&res_lis, stack_a);

	for (int i = 0; i < res_lis.len; i++)
		ft_printf("%d ", res_lis.arr[i]);
	ft_printf("\n");
}