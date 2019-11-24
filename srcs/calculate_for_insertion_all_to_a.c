/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_for_insertion_all_to_a.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 20:56:56 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 20:56:59 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/*
** explaination for get_wanted_top_a_value():
** For most cases, top of stack A should be a bigger int than to_a value
** but if (wanted_top_a_value>stk->max_len - 1), means this value doesn't exist
** because stk->max_len - 1 = the bigest integer value in list
** we will need find the smallest value on stack A and rotate to top
*/

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

/*
** steps_nb = steps needed to go to top b + steps needed to rotate a + 1 (pb)
*/

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

int		choose_best_to_push(t_stack *stk)
{
	int	best_value;
	int	i;
	int	min_steps;
	int	steps_nb;

	i = 0;
	while (i < stk->b_len)
	{
		steps_nb = calculate_steps(stk, stk->b[i], i);
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
