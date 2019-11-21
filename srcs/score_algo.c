/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:23:41 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/20 14:23:42 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *stk, char flags, FILE *fp, int *min_score)
{
	*min_score = 1000;
	while (stk->b_len < stk->max_len - 1 && *min_score)
	{
		pb(&stk, flags, fp);
		*min_score = execute_if_score_smaler(stk, flags, fp);
	}
}

void	push_back_to_a(t_stack *stk, char flags, FILE *fp, int *min_score)
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
	while (min_score)
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
	ft_printf("best score in total:%d\n", stk->count);
	return (stk->count);
}
