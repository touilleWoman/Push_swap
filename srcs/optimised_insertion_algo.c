/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_insertion_algo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:35:04 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 12:35:06 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	keep_rra_or_ra(t_stack *stk, char flags, FILE *fp, int to_top)
{
	int		to_top_pos;

	to_top_pos = position_on_stack(stk->a, stk->a_len, to_top);
	if (to_top_pos < 0)
		return ;
	if (stk->a_len - 1 - to_top_pos < to_top_pos + 1)
	{
		while (stk->a[stk->a_len - 1] != to_top)
			ra(&stk, flags, fp);
	}
	else
	{
		while (stk->a[stk->a_len - 1] != to_top)
			rra(&stk, flags, fp);
	}
}

/*
** explaination to : rra_or_ra(stk, flags, fp, 0)
** at this moment, stack B is empty, stack A is in good order,
** only need rotate stack A until 0 to the top.
*/

void	optimised_insertion_algo(t_stack *stk, char flags, FILE *fp)
{
	int	*mark;

	mark = mark_a(stk);
	push_marked_to_b(stk, mark, flags, fp);
	free(mark);
	mark = NULL;
	insert_all_to_a(stk, flags, fp);
	keep_rra_or_ra(stk, flags, fp, 0);
}
