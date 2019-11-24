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

/*
** steps_nb = steps needed to go to top b + steps needed to rotate a + 1 (pb)
*/
int		on_stack_b(t_stack *stk, int value)
{
	int		i;

	i = 0;
	while (i < stk->b_len)
	{
		if (stk->b[i] == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int		get_wanted_top_a_value(t_stack *stk, int to_a)
{
	int	wanted_top_a_value;

	wanted_top_a_value = to_a + 1;
	while (on_stack_b(stk, wanted_top_a_value) == TRUE)
		wanted_top_a_value++;
	if (wanted_top_a_value > stk->max_len - 1)
	{
		wanted_top_a_value = 0;
		while (on_stack_b(stk, wanted_top_a_value) == TRUE)
			wanted_top_a_value++;
	}
	return (wanted_top_a_value);
}
/*
** the closest value to to_a should be rotate to the top of stack A
** stk->max_len - 1 =  the bigest integer value in list
** if (wanted_top_a_value > stk->max_len - 1), means this value doesn't exist
** we will need find the smallest value on stack A and rotate to top
*/

int		calculate_rotate_a_steps(t_stack *stk, int to_a)
{
	int	wanted_top_a_value;
	int a_pos;
	int	rotate_a_steps;

	rotate_a_steps = 0;
	if (stk->a_len == 0 || stk->a_len == 1)
		return (0);
	wanted_top_a_value = get_wanted_top_a_value(stk, to_a);
	a_pos = position_on_stack(stk->a, stk->a_len, wanted_top_a_value);
	if (a_pos == -1)
	{
		printf("Error in calculate_rotate_a_steps\n");
	}
	if (stk->a_len - 1 - a_pos < a_pos + 1)
		rotate_a_steps = stk->a_len - 1 - a_pos;
	else
		rotate_a_steps = a_pos + 1;
	return (rotate_a_steps);
}






int		calculate_steps(t_stack *stk, int value, int value_pos)
{
	int	go_to_top_b_steps;
	int	rotate_a_steps;

	if (stk->b_len == 1)
		go_to_top_b_steps = 0;
	else if (stk->b_len - 1 - value_pos < value_pos + 1)
		go_to_top_b_steps = stk->b_len - 1 - value_pos;
	else
		go_to_top_b_steps = value_pos + 1;
	rotate_a_steps = calculate_rotate_a_steps(stk, value);
	return (go_to_top_b_steps + rotate_a_steps + 1);
}

static int		choose_best_to_push(t_stack *stk)
{
	int	best_value;
	int	i;
	int	min_steps;
	int	steps_nb;

	i = 0;
	while (i < stk->b_len)
	{
		steps_nb = calculate_steps(stk, stk->b[i], i);
		// printf("steps_nb= %d for value=%d\n",steps_nb, stk->b[i]);
		if (i == 0)
		{
			min_steps = steps_nb;
			best_value = stk->b[i];
		}
		else if (steps_nb < min_steps)
		{
			min_steps = steps_nb;
			best_value = stk->b[i];
		}
		i++;
	}
	return (best_value);
}

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

void	rotate_a_and_b(t_stack *stk, int to_a_value, char flags, FILE *fp)
{
	int				wanted_top_a_value;
	int				rotate_a_nb;
	int				rotate_b_nb;
	t_instruction 	which_for_a;
	t_instruction 	which_for_b;

	which_for_a = -1;
	which_for_b = -1;
	rotate_b_nb = -1;
 	rotate_a_nb = -1;
	if (stk->a_len > 1)
	{
		wanted_top_a_value = get_wanted_top_a_value(stk, to_a_value);
		rotate_a_nb = get_rotate_a_nb(stk, wanted_top_a_value, &which_for_a);
	}
	if (stk->b_len > 1)
		rotate_b_nb = get_rotate_b_nb(stk, to_a_value, &which_for_b);
	while (rotate_a_nb > 0 && rotate_b_nb > 0)
	{
		if (which_for_a == RA && which_for_b == RB)
			rr(&stk, flags, fp);
		else if (which_for_a == RRA && which_for_b == RRB)
			rrr(&stk, flags, fp);
		else if (which_for_a == RA && which_for_b == RRB)
		{
			ra(&stk, flags, fp);
			rrb(&stk, flags, fp);
		}
		else if (which_for_a == RRA && which_for_b == RB)
		{
			rra(&stk, flags, fp);
			rb(&stk, flags, fp);
		}
		rotate_b_nb--;
		rotate_a_nb--;
	}
	while (rotate_a_nb > 0)
	{
		if (which_for_a == RA)
			ra(&stk, flags, fp);
		else
			rra(&stk, flags, fp);
		rotate_a_nb--;
	}
	while (rotate_b_nb > 0)
	{
		if (which_for_b == RB)
			rb(&stk, flags, fp);
		else
			rrb(&stk, flags, fp);
		rotate_b_nb--;
	}
}

void	push_the_chosen_one(t_stack *stk, int to_a, char flags, FILE *fp)
{
	rotate_a_and_b(stk, to_a, flags, fp);
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
