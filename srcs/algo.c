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

// void	push_half_to_b(t_stack *stk, char flags, FILE *fp)
// {
// 	int		median;
// 	int		i;
// 	int		sorted[stk->max_len];

// 	ft_memcpy(sorted, args, sizeof(int) * nb_args);
// 	i = 0;
// 	median = find_median(stk->a, stk->a_len);
// 	while (i < (a_len / 2))
// 	{
// 		while (top1(stk, 'a') > median)
// 		{

// 		}
// 		pb();
// 		i++;
// 	}

// }

int			find_min(int *score_tab, int len, int *min_score)
{
	int		i;
	int		min_fun_index;

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

void		who_has_lowest_score(t_stack *stk, int flags)
{
	(void)flags;
	int	score_tab[11];
	int	min_score;
	int	min_fun_index;
	t_funs	funs[INSTRUCTION_NB] = {{SA, sa}, {SB, sb}, {SS, ss}, {PA, pa},
	{PB, pb}, {RA, ra}, {RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	int	i;

	i = 0;
	min_score = 1000;
	if (try_ins(stk, score_tab))
	{
		min_fun_index = find_min(score_tab, INSTRUCTION_NB, &min_score);
		ft_printf("functions index :%d, min_score=%d\n", min_fun_index, min_score);
		if (min_score < calculate_score(stk))
		{
			while (i < INSTRUCTION_NB)
			{
				if (funs[i].ins == min_fun_index)
				{
					funs[i].f(&stk, flags, NULL);
					break;
				}
				i++;
			}
		}
		else
		{
			pb(&stk, flags, NULL);
		}
	};



	// for (int i = 0; i < 11; ++i)
	// {
	// 	ft_printf("score_tab[%d]==%d\n",i, score_tab[i]);
	// }
}


void	score_algo(t_stack *stk, char flags, FILE *fp)
{
	(void)fp;
	while  (final_order_check(stk) == FALSE)
	{
		while(both_ab_right_order(stk) == FALSE)
		{
			who_has_lowest_score(stk, flags);
		}
		while (stk->a_len != stk->max_len)
			pa(&stk, flags, NULL);
		// if (stk->max_len == 2)
		// 	sa();
		// else
		// {
		// 	// push_back_to_a()
		// }


	}
	ft_printf("%d operations in total\n", stk->count);
}

void	algo(t_stack *stk, char flags, FILE *fp)
{
	// find_median(stk->a, stk->a_len);
	// while (final_order_check(stk) == FALSE)
	// 	one_round(stk, flags, fp);
	// ft_printf("%d operations in total\n", stk->count);

	score_algo(stk, flags, fp);
}