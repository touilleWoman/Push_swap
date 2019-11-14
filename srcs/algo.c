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

int		in_right_order(t_stack *stk, int nb_args)
{
	int		count;

	count = nb_args - 1;
	if (stk->b_len == 0 && stk->a_len == nb_args)
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
** it will choose rr or ss
*/
int		swap_or_rotate_a_done(t_stack *stk, FILE *fp, int *count, char flags)
{
	if(stk->a[stk->a_len - 1] > stk->a[stk->a_len - 2])
	{
		if (stk->a[stk->a_len - 1] > stk->a[0])
		{
			if (stk->b[stk->b_len - 1] < stk->b[stk->a_len - 2])
				rr(&stk, flags, fp, count);
			else
				ra(&stk, flags, fp, count);
		}
		else
		{
			if (stk->b[stk->b_len - 1] < stk->b[stk->a_len - 2])
				ss(&stk, flags, fp, count);
			else
				sa(&stk, flags, fp, count);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

int		swap_or_rotate_b_done(t_stack *stk, FILE *fp, int *count, char flags)
{
	if(stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
	{
		if (stk->b[stk->b_len - 1] < stk->b[0])
		{
			if (stk->a[stk->a_len - 1] > stk->a[stk->b_len - 2])
				rr(&stk, flags, fp, count);
			else
				rb(&stk, flags, fp, count);
		}
		else
		{
			if (stk->a[stk->a_len - 1] > stk->a[stk->b_len - 2])
				ss(&stk, flags, fp, count);
			else
				sb(&stk, flags, fp, count);
		}
		return (TRUE);
	}
	else
		return (FALSE);
}

void	one_round(t_stack *stk, char flags, FILE *fp, int *count, int nb_args)
{
	while (stk->a_len > 1)
	{
		while (swap_or_rotate_a_done(stk, fp, count, flags));
		if (in_right_order(stk, nb_args))
			return;
		pb(&stk, flags, fp, count);
		swap_or_rotate_b_done(stk, fp, count, flags);
	}
	while (stk->b_len > 1)
	{
		while (swap_or_rotate_b_done(stk, fp, count, flags));
		if (in_right_order(stk, nb_args))
			return;
		pa(&stk, flags, fp, count);
		swap_or_rotate_b_done(stk, fp, count, flags);
	}
	pa(&stk, flags, fp, count);
}

void	algo(t_stack *stk, int nb_args, char flags, FILE *fp)
{
	int		count;

	count = 0;
	while (in_right_order(stk, nb_args) == FALSE)
		one_round(stk, flags, fp, &count, nb_args);
	ft_printf("%d operations\n", count);
}