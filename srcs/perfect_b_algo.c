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
	ft_printf("perfect b in total:%d\n", stk->count);



}
