 

#include "push_swap.h"

int		both_ab_right_order(t_stack *stk)
{
	int		count;

	count = stk->a_len - 1;
	if (stk->a[stk->a_len - 1] - stk->b[stk->b_len - 1] != 1)
		return (FALSE);
	while (count)
	{
		if (stk->a[count] - stk->a[count - 1] != -1)
		{
			break;
		}
		count--;
	}
	if (count != 0)
		return (FALSE);
	if (stk->b_len == 0)
		return (TRUE);
	count = stk->b_len - 1;
	while (count)
	{
		if (stk->b[count] - stk->b[count - 1] != 1)
			break;
		count--;
	}
	if (count != 0)
		return (FALSE);
	return (TRUE);
}

int			find_min_in_scoretab(int *score_tab, int len, int *min_score)
{
	int		i;
	int		min_fun_index;

	*min_score = 1000;
	i = 0;
	min_fun_index = 0;
	while(i < len)
	{
		if (score_tab[i] < *min_score)
		{
			min_fun_index = i;
			*min_score = score_tab[i];
		}
		i++;
	}
	return(min_fun_index);
}

void		execute_ins(int fun_index, int flags, FILE *fp, t_stack *stk)
{
	t_funs	funs[9] = {{SA, sa}, {SB, sb}, {SS, ss}, {RA, ra}, {RB, rb},
	{RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};

	funs[fun_index].f(&stk, flags, fp);
}

int			get_min_score(t_stack *stk, int *min_fun_index, int *min_score)
{
	int	score_tab[9];

	if (try_ins(stk, score_tab))
	{
		*min_fun_index = find_min_in_scoretab(score_tab, 9, min_score);
		return (TRUE);
	};
	return (FALSE);
}

int		execute_if_score_smaler(t_stack *stk, char flags, FILE *fp)
{
	int	min_fun_index;
	int	min_score;
	int present_score;

	while (TRUE)
	{
		get_min_score(stk, &min_fun_index, &min_score);
		present_score = calculate_score(stk);
		if (min_score < present_score)
			execute_ins(min_fun_index, flags, fp, stk);
		if (min_score == 0 || min_score >= present_score)
			break;
	}
	return (min_score);
}

void 	push_to_b(t_stack *stk, char flags, FILE *fp, int *min_score)
{

	*min_score = 1000;
	while (stk->b_len < stk->max_len - 1 && *min_score)
	{
		pb(&stk, flags, fp);
		*min_score = execute_if_score_smaler(stk, flags, fp);
	}
}

void 	push_back_to_a(t_stack *stk, char flags, FILE *fp, int *min_score)
{
	*min_score = 1000;
	while (stk->a_len < stk->max_len - 1)
	{
		pa(&stk, flags, fp);
		*min_score = execute_if_score_smaler(stk, flags, fp);
	}
}

int		best_score_algo(t_stack *stk, char flags, FILE *fp, int last_algo_nb)
{
	int		min_score;
	int		i;

	i = 0;
	min_score = execute_if_score_smaler(stk, flags, fp);
	while(both_ab_right_order(stk) == FALSE && min_score)
	{
		push_to_b(stk, flags, fp, &min_score);
		min_score = execute_if_score_smaler(stk, flags, fp);
		push_back_to_a(stk, flags, fp, &min_score);
		i++;
		if (i > last_algo_nb)
			return (last_algo_nb + 1);
	}
	while (stk->a_len != stk->max_len)
		pa(&stk, flags, fp);
	return (stk->count);
}

void	choose_algo(t_stack *stk, char flags, FILE *fp)
{
	t_stack 	*cp;
	int			algo1_nb;
	int			algo2_nb;
	int			flags_for_test;

	flags_for_test = 0 | COUNT;
	cp = copy_stack(stk);
	perfect_b_algo(cp, flags_for_test, fp);
	algo1_nb = cp->count;
	free_push_swap_stack(cp);
	cp = copy_stack(stk);
	algo2_nb = best_score_algo(cp, flags_for_test, fp, algo1_nb);
	free_push_swap_stack(cp);
	if (algo1_nb < algo2_nb)
	{
		// ft_printf("perfect b  better\n\n\n\n");
		perfect_b_algo(stk, flags, fp);
	}
	else
	{
		// ft_printf("Score better\n\n\n\n");
		best_score_algo(stk, flags, fp, algo1_nb);
	}
}