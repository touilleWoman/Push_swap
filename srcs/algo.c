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

int		in_right_order(t_stack *stk)
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
		if (in_right_order(stk))
			return;
		pb(&stk, flags, fp);
		swap_or_rotate_b_done(stk, fp, flags);
	}
	while (stk->b_len > 1)
	{
		while (swap_or_rotate_b_done(stk, fp, flags));
		if (in_right_order(stk))
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

// void	median_algo(t_stack *stk, char flags, FILE *fp)
// {
// 	while (in_right_order(stk) == FALSE)
// 	{
// 		if (stk->a_len == 2)
// 			sa();
// 		else
// 			push_half_to_b(stk, flags, fp);
// 	}
// 	ft_printf("%d operations in total\n", stk->count);
// }

void	algo(t_stack *stk, char flags, FILE *fp)
{
	find_median(stk->a, stk->a_len);
	while (in_right_order(stk) == FALSE)
		one_round(stk, flags, fp);
	ft_printf("%d operations in total\n", stk->count);
}