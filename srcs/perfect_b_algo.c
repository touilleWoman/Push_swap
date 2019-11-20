/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_b_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:01:38 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/20 13:01:41 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		position_on_stack(int *tab, int tab_len, int value)
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
			break ;
		}
		i++;
	}
	return (value_pos);
}

void	rra_or_ra(t_stack *stk, char flags, FILE *fp, int to_b)
{
	int		to_b_pos;

	to_b_pos = position_on_stack(stk->a, stk->a_len, to_b);
	if (to_b_pos < 0)
		return ;
	if (to_b_pos < stk->a_len / 2)
	{
		while (stk->a[stk->a_len - 1] != to_b)
			rra(&stk, flags, fp);
	}
	else
	{
		while (stk->a[stk->a_len - 1] != to_b)
			ra(&stk, flags, fp);
	}
}

void	perfect_b_algo(t_stack *stk, char flags, FILE *fp)
{
	int		min_score;
	int		to_b;

	to_b = 0;
	min_score = execute_if_score_smaler(stk, flags, fp);
	while (stk->a_len != 1 && min_score)
	{
		rra_or_ra(stk, flags, fp, to_b);
		pb(&stk, flags, fp);
		to_b++;
	}
	while (stk->a_len != stk->max_len)
		pa(&stk, flags, fp);
}
