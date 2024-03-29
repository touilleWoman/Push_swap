/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:19:13 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 15:19:15 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** keep_nb initialised at 1, because head will be kept
*/

int		calculat_keep_nb(int *array, int arr_len, int head_pos)
{
	int	keep_nb;
	int	j;
	int	i;

	keep_nb = 1;
	i = head_pos;
	j = head_pos - 1;
	if (j == -1)
		j = arr_len - 1;
	while (j != head_pos)
	{
		if (array[j] > array[i])
		{
			keep_nb++;
			i = j;
		}
		j--;
		if (j == -1)
			j = arr_len - 1;
	}
	return (keep_nb);
}

int		find_best_head_value(int *array, int arr_len,
							int *best_keep_nb, int *best_head_pos)
{
	int	current;
	int	current_keep_nb;
	int	i;
	int	best_head_value;

	current = 0;
	current_keep_nb = 0;
	i = 0;
	while (i < arr_len)
	{
		current = array[i];
		current_keep_nb = calculat_keep_nb(array, arr_len, i);
		if (current_keep_nb > *best_keep_nb)
		{
			*best_keep_nb = current_keep_nb;
			best_head_value = current;
			*best_head_pos = i;
		}
		i++;
	}
	return (best_head_value);
}

int		*do_mark(t_stack *stk, int head, int head_pos)
{
	int		i;
	int		j;
	int		*mark;

	mark = (int*)malloc(sizeof(int) * (stk->a_len));
	if (!mark)
		return (NULL);
	mark[head] = KEEP;
	i = head_pos;
	j = head_pos - 1;
	(j == -1) ? j = stk->a_len - 1 : 0;
	while (j != head_pos)
	{
		if (stk->a[j] > stk->a[i])
		{
			mark[(stk->a)[j]] = KEEP;
			i = j;
		}
		else
			mark[(stk->a)[j]] = OUT;
		j--;
		(j == -1) ? j = stk->a_len - 1 : 0;
	}
	return (mark);
}

int		*mark_a(t_stack *stk)
{
	int	best_keep_nb;
	int	best_head;
	int best_head_pos;
	int	*mark;

	best_keep_nb = 0;
	best_head_pos = 0;
	best_head = find_best_head_value(stk->a, stk->a_len,
		&best_keep_nb, &best_head_pos);
	mark = do_mark(stk, best_head, best_head_pos);
	return (mark);
}
