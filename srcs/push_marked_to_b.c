/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_marked_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:03:33 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 21:03:36 by jleblond         ###   ########.fr       */
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

static int					try_rra(t_stack *cp, int *mark, int out_nb)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < out_nb)
	{
		while (mark[cp->a[cp->a_len - 1]] != OUT)
		{
			rra(&cp, 0, 0);
			count++;
		}
		i++;
	}
	return (count);
}

static int					try_ra(t_stack *cp, int *mark, int out_nb)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (i < out_nb)
	{
		while (mark[cp->a[cp->a_len - 1]] != OUT)
		{
			ra(&cp, 0, 0);
			count++;
		}
		i++;
	}
	return (count);
}

t_instruction		copy_stack_to_test_steps(t_stack *stk, int *mark, int out_nb)
{
	t_stack *cp;
	int		count_for_ra;
	int		count_for_rra;

	cp = copy_stack(stk);
	count_for_rra = 0;
	count_for_ra = 0;
	count_for_rra = try_rra(cp, mark, out_nb);
	free_push_swap_stack(cp);
	cp = copy_stack(stk);
	count_for_ra = try_ra(cp, mark, out_nb);
	free_push_swap_stack(cp);
	if (count_for_ra > count_for_rra)
		return (RRA);
	else
		return (RA);
}

void	push_marked_to_b(t_stack *stk, int *mark, char flags, FILE *fp)
{
	int				out_nb;
	t_instruction	better;

	out_nb = nb_to_be_kicked_out(mark, stk->max_len);
	better = copy_stack_to_test_steps(stk, mark, out_nb);
	while (out_nb > 0)
	{
		while (mark[stk->a[stk->a_len - 1]] != OUT)
		{
			if (better == RRA)
				rra(&stk, flags, fp);
			else if (better == RA)
				ra(&stk, flags, fp);
		}
		pb(&stk, flags, fp);
		out_nb--;
	}
}