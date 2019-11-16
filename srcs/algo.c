/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 16:24:59 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/14 16:25:01 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		final_order_check(t_stack *stk)
{
	int		count;

	count = stk->max_len - 1;
	if (stk->b_len == 0 && stk->a_len == stk->max_len)
	{
		while (count)
		{
			if (stk->a[count] > stk->a[count - 1])
				break ;
			count--;
		}
		if (count == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

int		both_ab_right_order(t_stack *stk)
{
	int		count;

	count = stk->a_len - 1;
	while (count)
	{
		if (stk->a[count] > stk->a[count - 1])
			break;
		count--;
	}
	if (count != 0)
		return (FALSE);
	if (stk->b_len == 0)
		return (TRUE);
	count = stk->b_len - 1;
	while (count)
	{
		if (stk->b[count] < stk->b[count - 1])
			break;
		count--;
	}
	if (count != 0)
		return (FALSE);
	return (TRUE);
}

/*
** I want to swap or rotate a or b, but if rr or ss shold be used,
** it will choose rr or ss rather than sa ra sb rb
*/
int		swap_or_rotate_a_done(t_stack *stk, FILE *fp, char flags)
{

	if(top2_exist(stk, 'a') && top1(stk, 'a') > top2(stk, 'a'))
	{
		if (top1(stk, 'a') > stk->a[0])
		{
			if (top2_exist(stk, 'b') &&  top1(stk, 'b') < top2(stk, 'b'))
				rr(&stk, flags, fp);
			else
				ra(&stk, flags, fp);
		}
		else
		{
			if (top2_exist(stk, 'b') && top1(stk, 'b') < top2(stk, 'b'))
				ss(&stk, flags, fp);
			else
				sa(&stk, flags, fp);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

int		swap_or_rotate_b_done(t_stack *stk, FILE *fp, char flags)
{
	if(top2_exist(stk, 'b') && top1(stk, 'b') < top2(stk, 'b'))
	{
		if (top1(stk, 'b') < stk->b[0])
		{
			if (top2_exist(stk, 'a') && top1(stk, 'a') > top2(stk, 'a'))
				rr(&stk, flags, fp);
			else
				rb(&stk, flags, fp);
		}
		else
		{
			if ( top2_exist(stk, 'a') && top1(stk, 'a') > top2(stk, 'a'))
				ss(&stk, flags, fp);
			else
				sb(&stk, flags, fp);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

void	one_round(t_stack *stk, char flags, FILE *fp)
{
	while (stk->a_len > 1)
	{
		while (swap_or_rotate_a_done(stk, fp, flags));
		if (final_order_check(stk))
			return;
		pb(&stk, flags, fp);
		swap_or_rotate_b_done(stk, fp, flags);
	}
	while (stk->b_len > 1)
	{
		while (swap_or_rotate_b_done(stk, fp, flags));
		if (final_order_check(stk))
			return;
		pa(&stk, flags, fp);
		swap_or_rotate_b_done(stk, fp, flags);
	}
	pa(&stk, flags, fp);
}

// void	swap_or_rotate_a(t_stack *stk, int median)
// {
// 	int top1;
// 	int	top2;
// 	int	top3;

// 	if (top)
// 	{
// 		/* code */
// 	}


// }



int			find_min(int *score_tab, int len, int *min_score)
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

// void		execute_ins(int fun_index, int flags, FILE *fp, t_stack *stk)
// {
// 	t_funs	funs[INSTRUCTION_NB] = {{SA, sa}, {SB, sb}, {SS, ss}, {PA, pa},
// 	{PB, pb}, {RA, ra}, {RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
// 	};
// 	int	i;

// 	i = 0;
// 	while (i < INSTRUCTION_NB)
// 	{
// 		if (funs[i].ins == fun_index)
// 		{
// 			funs[i].f(&stk, flags, fp);
// 			break;
// 		}
// 		i++;
// 	}
// }
void		execute_ins(int fun_index, int flags, FILE *fp, t_stack *stk)
{
	t_funs	funs[9] = {{SA, sa}, {SB, sb}, {SS, ss}, {RA, ra}, {RB, rb},
	{RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	// int	i;

	// i = 0;
	// while (i < 9)
	// {
	// 	// if (funs[i].ins == fun_index)
	// 	// {
	// 		funs[i].f(&stk, flags, fp);
	// 		// break;
	// 	}
	// 	i++;
	// }
	funs[fun_index].f(&stk, flags, fp);
	ft_printf("fun_index:%d\n", fun_index);
	//
}

int			get_min_score(t_stack *stk, int *min_fun_index, int *min_score)
{
	int	score_tab[9];

	if (try_ins(stk, score_tab))
	{
		// for (int i = 0; i < 9; ++i)
		// {
		// 	ft_printf("score_tab[%d] =%d\n", i, score_tab[i]);
		// }
		*min_fun_index = find_min(score_tab, 9, min_score);
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
		ft_printf("min_score=%d, present_score=%d, min_fun_index=%d\n", min_score, present_score, min_fun_index);
	}
	return (min_score);
}

void	score_algo(t_stack *stk, char flags, FILE *fp)
{
	int	min_fun_index;
	int	min_score;

	min_fun_index = 0;
	min_score = 1000;

	// while  (final_order_check(stk) == FALSE)
	// {
		min_score = execute_if_score_smaler(stk, flags, fp);
		while(min_score != 0)
		{
			while (stk->a_len > 1  && min_score != 0)
			{
				pb(&stk, flags, fp);
				min_score = execute_if_score_smaler(stk, flags, fp);
				// printf("============%d\n", min_score);

				if (min_score == 0)
				{
					break;
				}
			}
			while (stk->b_len > 1 && min_score != 0)
			{
				pa(&stk, flags, fp);
				min_score = execute_if_score_smaler(stk, flags, fp);
				if (min_score == 0)
				{
					break;
				}
			}
		}
		min_score = execute_if_score_smaler(stk, flags, fp);
 		while (stk->a_len != stk->max_len)
			pa(&stk, flags, fp);
		// if (stk->max_len == 2)
		// 	sa();
		// else
		// {
		// 	// push_back_to_a()
		// }


	// }
	ft_printf("%d operations in total\n", stk->count);
}

void	algo(t_stack *stk, char flags, FILE *fp)
{
	// t_stack *cp;

	// cp = copy_stack(stk);
	// while (final_order_check(stk) == FALSE)
	// 	one_round(stk, flags, fp);
	// ft_printf("%d operations in total\n", stk->count);

	score_algo(stk, flags, fp);

}