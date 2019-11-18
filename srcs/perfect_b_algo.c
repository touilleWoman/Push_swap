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

void	perfect_b_algo(t_stack *stk, char flags, FILE *fp)
{
	int		min_score;
	int		to_b;
	int 	value_pos;

	to_b = 0;
	min_score = 1000;
	min_score = execute_if_score_smaler(stk, flags, fp);
	value_pos = -1;
	while (stk->a_len != 1 && min_score)
	{
		value_pos = position_on_stack(stk->a, stk->a_len, to_b);
		if (value_pos < 0)
			return ;
		if (value_pos < stk->a_len / 2)
		{
			while (stk->a[stk->a_len - 1] != to_b)
				rra(&stk, flags, fp);
		}
		else
		{
			while (stk->a[stk->a_len - 1] != to_b)
				ra(&stk, flags, fp);
		}
		pb(&stk, flags, fp);
		to_b++;
	}
 	while (stk->a_len != stk->max_len)
		pa(&stk, flags, fp);
	ft_printf("Perfect B %d operations in total\n", stk->count);
}

