/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:16:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/15 14:16:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*incomplete_copy_stack_for_try(t_stack *stk)
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

int			try_ins(t_stack *stk, int *score)
{
	static t_funs	funs[9] = {
	{SA, sa}, {SB, sb}, {SS, ss},
	{RA, ra}, {RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	int				i;
	t_stack			*cp;

	i = 0;
	while (i < 9)
	{
		cp = incomplete_copy_stack_for_try(stk);
		if (!cp)
			return (FALSE);
		funs[i].f(&cp, 0, NULL);
		score[i] = calculate_score(cp);
		free_push_swap_stack(cp);
		i++;
	}
	return (TRUE);
}

int			calculate_score(t_stack *stk)
{
	int		score;
	int		al;
	int		bl;

	al = stk->a_len;
	bl = stk->b_len;
	score = 0;
	if (al > 0 && bl > 0)
	{
		if (stk->a[al - 1] - stk->b[bl - 1] != 1)
			score++;
	}
	while (al > 1)
	{
		if (stk->a[al - 1] - stk->a[al - 2] != -1)
			score++;
		al--;
	}
	while (bl > 1)
	{
		if (stk->b[bl - 1] - stk->b[bl - 2] != 1)
			score++;
		bl--;
	}
	return (score);
}
