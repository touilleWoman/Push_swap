#include "push_swap.h"

int		position_on_stack(int *tab,  int tab_len, int value)
{
	int	i;
	int	value_pos;

	i = 0;
	value_pos = -1;
	while (i < tab_len)
	{
		if (tab[i] == value)
		{
			value_pos = i;
			break;
		}
		i++;
	}
	return (value_pos);
}

void 	push_median(t_stack *stk, char flags, FILE *fp, int median)
{
	int value_pos;

	value_pos = position_on_stack(stk->a, stk->a_len, median);
	if (value_pos < 0)
		return ;
	if (value_pos < stk->a_len / 2)
	{
		while (stk->a[stk->a_len - 1] != median)
			rra(&stk, flags, fp);
	}
	else
	{
		while (stk->a[stk->a_len - 1] != median)
			ra(&stk, flags, fp);
	}
	pb(&stk, flags, fp);
}

void	median_algo(t_stack *stk, char flags, FILE *fp)
{
	int		median;
	int		min_score;
	int		diff;
	int		need_two_round;

	int		i = 0;

	min_score = 1000;
	median = stk->max_len / 2;
	diff = 1;
	need_two_round = 0;
	min_score = execute_if_score_smaler(stk, flags, fp);
	if (min_score != 0)
		push_median(stk, flags, fp, median);
	while (stk->a_len != 0)
	{
		while (stk->a[stk->a_len - 1] - median != diff && stk->a[stk->a_len - 1] - median != -diff)
			ra(&stk, flags, fp);
		need_two_round++;
		pb(&stk, flags, fp);
		if (stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
			rb(&stk, flags, fp);
		if (need_two_round == 2)
		{
			diff++;
			need_two_round = 0;
		}
		i++;
	}
 	while (stk->a_len != stk->max_len)
		pa(&stk, flags, fp);
	// ft_printf("%d operations in total\n", stk->count);
}
