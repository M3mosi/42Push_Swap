#include "pushswap.h"

typedef struct	s_calcolo
{
	int			strategy;
	int			i_A;
	int			i_B;
}				t_calcolo;

int		error(t_stack *s)
{
	int i;

	i = 0;
	while (i < s->len - 1)
	{
		if (s->indexed[i] > s->indexed[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int		index_min(t_stack *s)
{
	int min;
	int index;
	int i;

	i = 0;
	min = MAX_INT;
	index = 0;
	while (s->indexed[i])
	{
		if (s->indexed[i] < min)
		{
			min = s->indexed[i];
			index = i;
		}
		i++;
	}
	return index;
}

void 	final_algo(t_stack *s_A, t_stack *s_B)
{
	int			MOVES;
	int			same_moves;
	t_calcolo	calc;

	ft_printf("SORT START\n");
	MOVES = 0;
	while (error(s_A) != 0 || s_B->len != 0)
	{
		//arr_dist, strategy, min, min_strategy, _iA, _iB = calcolo_dist(arr_a.copy(), arr_b.copy())

		//111 == TOP - NORM - NORM
		if (calc.strategy == 111)
		{
			while (calc.i_A--)
			{
				move(s_A, s_B, "ra");
				MOVES++;	
			}
			while (calc.i_B--)
			{
				move(s_A, s_B, "rb");
				MOVES++;		
			}			
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//121 == TOP - INV - NORM
		else if (calc.strategy == 121)
		{
			while (s_A->len - calc.i_A--)
			{
				move(s_A, s_B, "rra");
				MOVES++;		
			}
			while (calc.i_B--)
			{
				move(s_A, s_B, "rb");
				MOVES++;		
			}			
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//112 == TOP - NORM - INV
		else if (calc.strategy == 112)
		{
			while (calc.i_A--)
			{
				move(s_A, s_B, "ra");
				MOVES++;		
			}
			while (s_B->len - calc.i_B--)
			{
				move(s_A, s_B, "rrb");
				MOVES++;		
			}			
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//122 == TOP - INV - INV
		else if (calc.strategy == 122)
		{
			while (s_A->len - calc.i_A--)
			{
				move(s_A, s_B, "rra");
				MOVES++;		
			}
			while (s_B->len - calc.i_B--)
			{
				move(s_A, s_B, "rrb");
				MOVES++;		
			}			
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//211 == SAME - NORM - NORM
		else if (calc.strategy == 211)
		{
			same_moves = 0;
			if (calc.i_A > 0 && calc.i_B > 0 && calc.i_A < calc.i_B)
				same_moves = calc.i_A;
			else if (calc.i_A > 0 && calc.i_B > 0 && calc.i_A > calc.i_B)
				same_moves = calc.i_B;
			calc.i_A -= same_moves;
			calc.i_B -= same_moves;
			while (same_moves--)
			{
				move(s_A, s_B, "rr");
				MOVES++;
			}
			while (calc.i_A--)
			{
				move(s_A, s_B, "ra");
				MOVES++;		
			}
			while (calc.i_B--)
			{
				move(s_A, s_B, "rb");
				MOVES++;		
			}	
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//222 == SAME - INV - INV
		else if (calc.strategy == 222)
		{
			same_moves = 0;
			if (calc.i_A > 0 && calc.i_B > 0 && s_A->len - calc.i_A < s_B->len - calc.i_B)
				same_moves = s_A->len - calc.i_A;
			else if (calc.i_A > 0 && calc.i_B > 0 && s_A->len - calc.i_A > s_B->len - calc.i_B)
				same_moves = s_B->len - calc.i_B;
			calc.i_A -= same_moves;
			calc.i_B -= same_moves;
			while (same_moves--)
			{
				move(s_A, s_B, "rrr");
				MOVES++;
			}
			while (calc.i_A--)
			{
				move(s_A, s_B, "rra");
				MOVES++;		
			}
			while (calc.i_B--)
			{
				move(s_A, s_B, "rrb");
				MOVES++;
			}	
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//321 == DIFF - INV - NORM
		else if (calc.strategy == 321)
		{
			while (s_A->len - calc.i_A--)
			{
				move(s_A, s_B, "rra");
				MOVES++;		
			}
			while (calc.i_B--)
			{
				move(s_A, s_B, "rb");
				MOVES++;
			}	
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//312 == DIFF - NORM - INV
		else if (calc.strategy == 312)
		{
			while (calc.i_A--)
			{
				move(s_A, s_B, "ra");
				MOVES++;		
			}
			while (s_B->len - calc.i_B--)
			{
				move(s_A, s_B, "rrb");
				MOVES++;
			}	
			move(s_A, s_B, "pa");
			MOVES++;
		}
		//999 == EXIT
		else if (calc.strategy == 999)
			break;
	}
	while (error(s_A) != 0)
	{	
		if (index_min(s_A) == 0)
			break;

		if (index_min(s_A) < s_A->len / 2)
		{
			move(s_A, s_B, "ra");
			MOVES++;
		}
		else
		{
			move(s_A, s_B, "rra");
			MOVES++;
		}
	}
}