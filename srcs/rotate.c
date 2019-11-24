/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:13:32 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 21:13:34 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_rotate_a_nb(t_stack *stk, int to_top, t_instruction *which)
{
	int		to_top_pos;

	to_top_pos = position_on_stack(stk->a, stk->a_len, to_top);
	if (to_top_pos < 0)
		return (-1);
	if (stk->a_len - 1 - to_top_pos < to_top_pos + 1)
	{
		*which = RA;
		return (stk->a_len - 1 - to_top_pos);
	}
	else
	{
		*which = RRA;
		return (to_top_pos + 1);
	}
}

int		get_rotate_b_nb(t_stack *stk, int to_top, t_instruction *which)
{
	int		to_top_pos;

	to_top_pos = position_on_stack(stk->b, stk->b_len, to_top);
	if (to_top_pos < 0)
		return (-1);
	if (stk->b_len - 1 - to_top_pos < to_top_pos + 1)
	{
		*which = RB;
		return (stk->b_len - 1 - to_top_pos);
	}
	else
	{
		*which = RRB;
		return (to_top_pos + 1);
	}
}

void	rotate_both(t_stack *stk, char flags, FILE *fp, t_rotate *r)
{
	while (r->a_nb > 0 && r->b_nb > 0)
	{
		if (r->a_direction == RA && r->b_direction == RB)
			rr(&stk, flags, fp);
		else if (r->a_direction == RRA && r->b_direction == RRB)
			rrr(&stk, flags, fp);
		else if (r->a_direction == RA && r->b_direction == RRB)
		{
			ra(&stk, flags, fp);
			rrb(&stk, flags, fp);
		}
		else if (r->a_direction == RRA && r->b_direction == RB)
		{
			rra(&stk, flags, fp);
			rb(&stk, flags, fp);
		}
		r->b_nb--;
		r->a_nb--;
	}
}

void	rotate_a_then_b(t_stack *stk, char flags, FILE *fp, t_rotate *r)
{
	while (r->a_nb > 0)
	{
		if (r->a_direction == RA)
			ra(&stk, flags, fp);
		else
			rra(&stk, flags, fp);
		r->a_nb--;
	}
	while (r->b_nb > 0)
	{
		if (r->b_direction == RB)
			rb(&stk, flags, fp);
		else
			rrb(&stk, flags, fp);
		r->b_nb--;
	}
}

void	best_way_to_rotate(t_stack *stk, int to_a_value, char flags, FILE *fp)
{
	int				wanted_top_a_value;
	t_rotate		r;

	r.a_direction = -1;
	r.b_direction = -1;
	r.b_nb = -1;
 	r.a_nb = -1;
	if (stk->a_len > 1)
	{
		wanted_top_a_value = get_wanted_top_a_value(stk, to_a_value);
		r.a_nb = get_rotate_a_nb(stk, wanted_top_a_value, &r.a_direction);
	}
	if (stk->b_len > 1)
		r.b_nb = get_rotate_b_nb(stk, to_a_value, &r.b_direction);
	rotate_both(stk, flags, fp, &r);
	rotate_a_then_b(stk, flags, fp, &r);
}
