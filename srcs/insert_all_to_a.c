/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_all_to_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:24:24 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 15:24:26 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_the_chosen_one(t_stack *stk, int to_a, char flags, FILE *fp)
{
	best_way_to_rotate(stk, to_a, flags, fp);
	pa(&stk, flags, fp);
}

void	insert_all_to_a(t_stack *stk, char flags, FILE *fp)
{
	int	to_a;
	int	to_a_pos;

	to_a_pos = 0;
	while (stk->b_len != 0)
	{
		to_a = choose_best_to_push(stk);
		push_the_chosen_one(stk, to_a, flags, fp);
	}
}
