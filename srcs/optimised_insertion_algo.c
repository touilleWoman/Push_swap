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

int		nb_to_be_kicked_out(int *mark, int len)
{
	int	i;
	int out_nb;

	out_nb = 0;
	i = 0;
	while (i < len)
	{
		if (mark[i] == OUT)
			out_nb++;
		i++;
	}
	return (out_nb);
}

void	push_marked_to_b(t_stack *stk, int *mark, char flags, FILE *fp)
{
	int	out_nb;

	out_nb = nb_to_be_kicked_out(mark, stk->max_len);
	while (out_nb > 0)
	{
		while (mark[stk->a[stk->a_len - 1]] != OUT)
			ra(&stk, flags, fp);
		pb(&stk, flags, fp);
		out_nb--;
	}
}

/*
** explaination to : rra_or_ra(stk, flags, fp, 0)
** at this moment, stack B is empty, stack A is in good order,
** only need rotate 0 to the top.
*/

void	optimised_insertion_algo(t_stack *stk, char flags, FILE *fp)
{
	int	*mark;

	mark = mark_a(stk);
	push_marked_to_b(stk, mark, flags, fp);
	insert_all_to_a(stk, flags, fp);
	rra_or_ra(stk, flags, fp, 0);
	// printf("In total, optimised_insertion_algo: %d\n", stk->count);
}
