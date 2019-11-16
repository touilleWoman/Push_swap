/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:16:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/15 14:16:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack 	*copy_stack(t_stack *stk)
{
	t_stack	*cp;

	cp = (t_stack*)malloc(sizeof(t_stack));
	if (!cp)
		return (NULL);
	ft_bzero(cp, sizeof(t_stack));
	cp->a = (int*)malloc(sizeof(int) * stk->max_len);
	if (!cp->a)
	{
		free(cp);
		return (NULL);
	}
	cp->b = (int*)malloc(sizeof(int) * stk->max_len);
	if (!cp->b)
	{
		free(cp->a);
		free(cp);
		return (NULL);
	}
	ft_memcpy(cp->a, stk->a, sizeof(int) * stk->max_len);
	ft_memcpy(cp->b, stk->b, sizeof(int) * stk->max_len);
	cp->a_len = stk->a_len;
	cp->b_len = stk->b_len;
	return (cp);
}

int 	try_ins(t_stack *stk, int *score)
{
	t_funs	funs[INSTRUCTION_NB] = {{SA, sa}, {SB, sb}, {SS, ss}, {PA, pa},
	{PB, pb}, {RA, ra}, {RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	int	i;
	t_stack *cp;


	i = 0;
	while (i < INSTRUCTION_NB)
	{
		cp = copy_stack(stk);
		if (!cp)
			return (FALSE);
		funs[i].f(&cp, 0 , NULL);
		score[i] = calculate_score(cp);
		// if (score[i] == 0)
		// 	break;
		// printf("run score test%d\n", score);
		free_push_swap_stack(cp);
		i++;
	}
	return (TRUE);
}
