/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:30:52 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/23 14:30:54 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_half_to_b(t_stack *stk, char flags, FILE *fp)
{
	int		to_b_nb;
	int		median;
	// int		to_b_nb_total;

	median = stk->max_len / 2;
	// if (stk->max_len % 2 == 0)
	// 	to_b_nb_total = median + 1;
	// else
	// 	to_b_nb_total = median;

	to_b_nb = 0;
	while (to_b_nb < median)
	{
		while (stk->a[stk->a_len - 1] >= median)
			ra(&stk, flags, fp);
		pb(&stk, flags, fp);
		to_b_nb++;
	}
}

void	push_another_half_to_b(t_stack *stk, char flags, FILE *fp)
{
	int		to_b_nb;
	int		median;

	median = stk->max_len / 2;
	to_b_nb = stk->max_len - median + 1;
	while (to_b_nb > 0)
	{
		rra(&stk, flags, fp);
		pb(&stk, flags, fp);
		to_b_nb--;
	}
}

void	rrb_or_rb(t_stack *stk, char flags, FILE *fp, int to_a)
{
	int		to_a_pos;

	to_a_pos = position_on_stack(stk->b, stk->b_len, to_a);
	// printf("==============:%d, %d\n", to_a, to_a_pos);
	if (to_a_pos < 0)
	{
		ft_printf("Error in rrb_or_rrb()\n");
		return ;
	}
	if (to_a_pos < stk->b_len / 2)
	{
		while (stk->b[stk->b_len - 1] != to_a)
			rrb(&stk, flags, fp);
	}
	else
	{
		while (stk->b[stk->b_len - 1] != to_a)
			rb(&stk, flags, fp);
	}
}

void	push_half_back_to_a(t_stack *stk, char flags, FILE *fp)
{
	int		to_a_pos;
	int		to_a;

	to_a = stk->max_len / 2 - 1;
	to_a_pos = position_on_stack(stk->b, stk->b_len, to_a);
	// printf("==============:%d, %d\n", to_a, to_a_pos);
	if (to_a_pos == -1)
		ft_putendl_fd("Error in algo median!\n", 2);
	while (stk->b_len != 0)
	{
		while (stk->b[stk->b_len - 1] != to_a)
			rrb_or_rb(stk, flags, fp, to_a);
		pa(&stk, flags, fp);
		to_a--;
	}
}

void	push_another_half_back_to_a(t_stack *stk, char flags, FILE *fp)
{
	int		to_a_pos;
	int		to_a;

	to_a = stk->max_len / 2 - 1;
	to_a_pos = position_on_stack(stk->b, stk->b_len, to_a);
	// printf("==============:%d, %d\n", to_a, to_a_pos);
	if (to_a_pos == -1)
		ft_putendl_fd("Error in algo median!\n", 2);
	while (stk->b_len != 0)
	{
		if (stk->b[stk->b_len - 1] != to_a)
			rrb_or_rb(stk, flags, fp, to_a);
		pa(&stk, flags, fp);
		ra(&stk, flags, fp);
		to_a++;
	}
}

void	quick_sort_algo(t_stack *stk, char flags, FILE *fp)
{
	int		min_score;

	// min_score = execute_if_score_smaler(stk, flags, fp);
	// if (min_score)
	// {
		small_half_to_b(stk, flags, fp);
		push_half_back_to_a(stk, flags, fp);
		push_another_half_to_b(stk, flags, fp);
		push_another_half_back_to_a(stk, flags, fp);
	// }
	ft_printf("quick_sort in total:%d\n", stk->count);
}