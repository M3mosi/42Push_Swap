#include "pushswap.h"

typedef struct	s_calcolo
{
	int			strategy;
	int			i_A;
	int			i_B;
}				t_calcolo;

int		index_min(t_stack *s)
{
	int min;
	int index;
	int i;

	i = 0;
	min = MAX_INT;
	index = 0;
	while (i < s->len)
	{
		if (s->indexed[i] <= min)
		{
			min = s->indexed[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int		index_max(t_stack *s)
{
	int max;
	int index;
	int i;

	i = 0;
	max = MIN_INT;
	index = 0;
	while (i < s->len)
	{
		if (s->indexed[i] >= max)
		{
			max = s->indexed[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void calcolo_dist(t_stack *s_A, t_stack *s_B, t_calcolo *calc)
{
	int min;
	int *arr_dist;
	int *arr_strategy;
	int i;
	int	not_find;
	int dir_B;
	int dist_B;
	int dir_A;
	int dist_A;
	int j;
	int prec_A;


	min = MAX_INT;
	arr_dist = ft_calloc(s_B->len, sizeof(int));
	arr_strategy = ft_calloc(s_B->len, sizeof(int));
	calc->i_A = 0;
	calc->i_B = 0;
	calc->strategy = 999;
	i = 0;
	while (i < s_B->len)
	{
		not_find = 1;
		dir_B = calc_dir(s_B, s_B->indexed[i]);
		dist_B = calc_dist(s_B, s_B->indexed[i]);
		j = 0;
		while (j < s_A->len)
		{
			dir_A = calc_dir(s_A, s_A->indexed[j]);
			dist_A = calc_dist(s_A, s_A->indexed[j]);
			if (j == 0)
				prec_A = s_A->indexed[s_A->len - 1];
			else
				prec_A = s_A->indexed[j - 1];
			//SAME
			if (s_B->indexed[i] < s_A->indexed[j] && s_B->indexed[i] > prec_A && dir_A == dir_B)
			{
				if (dist_B > dist_A)
					arr_dist[i] = dist_B;
				else
					arr_dist[i] = dist_A;
				arr_strategy[i] = 200 + (dir_A * 10) + dir_B;
				not_find = 0;
				break;
			}
			//DIFF
			else if (s_B->indexed[i] < s_A->indexed[j] && s_B->indexed[i] > prec_A && dir_A != dir_B)
			{
				arr_dist[i] = dist_A + dist_B;
				arr_strategy[i] = 300 + (dir_A * 10) + dir_B;
				not_find = 0;
				break;
			}
			j++;
		}
		if (not_find)
		{
			j = index_max(s_A);
			dir_A = calc_dir(s_A, s_A->indexed[j]);
			dist_A = calc_dist(s_A, s_A->indexed[j]);
			j++;
			arr_dist[i] = dist_A + dist_B + 1;
			arr_strategy[i] = 100 + (dir_A * 10) + dir_B;
		}	
		if (arr_dist[i] < min)
		{
			calc->strategy = arr_strategy[i];
			calc->i_A = j;
			calc->i_B = i;
			min = arr_dist[i];
		}
		i++;
	}
	free(arr_dist);
	free(arr_strategy);
}

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

void 	final_algo(t_stack *s_A, t_stack *s_B)
{
	int			same_moves;
	int			i;
	t_calcolo	calc;

	while (error(s_A) != 0 || s_B->len != 0)
	{
		calcolo_dist(s_A, s_B, &calc);
		//111 == TOP - NORM - NORM
		ft_printf("%d\n", s_A->tot_move);
		if (calc.strategy == 111)
		{
			while (calc.i_A--)
				move(s_A, s_B, "ra");
			while (calc.i_B--)
				move(s_A, s_B, "rb");			
			move(s_A, s_B, "pa");
		}
		//121 == TOP - INV - NORM
		else if (calc.strategy == 121)
		{
			i = s_A->len - calc.i_A;
			while (i > 0)
			{
				move(s_A, s_B, "rra");
				i--;		
			}
			while (calc.i_B--)
				move(s_A, s_B, "rb");		
			move(s_A, s_B, "pa");
		}
		//112 == TOP - NORM - INV
		else if (calc.strategy == 112)
		{
			i = s_B->len - calc.i_B;
			while (calc.i_A--)
				move(s_A, s_B, "ra");
			while (i > 0)
			{
				move(s_A, s_B, "rrb");
				i--;
			}			
			move(s_A, s_B, "pa");
		}
		//122 == TOP - INV - INV
		else if (calc.strategy == 122)
		{
			i = s_A->len - calc.i_A;
			while (i > 0)
			{
				move(s_A, s_B, "rra");
				i--;		
			}
			i = s_B->len - calc.i_B;
			while (i > 0)
			{
				move(s_A, s_B, "rrb");
				i--;		
			}			
			move(s_A, s_B, "pa");
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
				move(s_A, s_B, "rr");
			while (calc.i_A--)
				move(s_A, s_B, "ra");
			while (calc.i_B--)
				move(s_A, s_B, "rb");
			move(s_A, s_B, "pa");
		}
		//222 == SAME - INV - INV
		else if (calc.strategy == 222)
		{
			same_moves = 0;
			if (calc.i_A > 0 && calc.i_B > 0 && s_A->len - calc.i_A < s_B->len - calc.i_B)
				same_moves = s_A->len - calc.i_A;
			else if (calc.i_A > 0 && calc.i_B > 0 && s_A->len - calc.i_A > s_B->len - calc.i_B)
				same_moves = s_B->len - calc.i_B;
			i = same_moves;
			while (i > 0)
			{
				move(s_A, s_B, "rrr");
				i--;
			}
			i = s_A->len - calc.i_A - same_moves;
			while (i > 0)
			{
				move(s_A, s_B, "rra");
				i--;		
			}
			i = s_B->len - calc.i_B - same_moves;
			while (i > 0)
			{
				move(s_A, s_B, "rrb");
				i--;
			}	
			move(s_A, s_B, "pa");
		}
		//321 == DIFF - INV - NORM
		else if (calc.strategy == 321)
		{
			i = s_A->len - calc.i_A;
			while (i > 0)
			{
				move(s_A, s_B, "rra");
				i--;
			}
			while (calc.i_B--)
				move(s_A, s_B, "rb");
			move(s_A, s_B, "pa");
		}
		//312 == DIFF - NORM - INV
		else if (calc.strategy == 312)
		{
			while (calc.i_A--)
				move(s_A, s_B, "ra");
			i = s_B->len - calc.i_B;
			while (i > 0)
			{
				move(s_A, s_B, "rrb");
				i--;
			}
			move(s_A, s_B, "pa");
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
			move(s_A, s_B, "ra");
		else
			move(s_A, s_B, "rra");
	}
}