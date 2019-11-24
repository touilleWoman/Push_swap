/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimised_insertion_algo.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:35:04 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/24 12:35:06 by jleblond         ###   ########.fr       */
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

int		find_best_head_value(int *array, int arr_len, int *best_keep_nb, int *best_head_pos)
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
		// printf("keep_nb for %d(array[%d]) is %d \n", current, i, current_keep_nb);
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



int		*do_mark(t_stack *stk, int head, int head_pos, int keep_nb)
{
	int		i;
	int		j;
	int		*mark;
	int		count;//delete later

	mark = (int*)malloc(sizeof(int) * (stk->a_len));
	if (!mark)
		return (NULL);
	mark[head] = KEEP;
	i = head_pos;
	j = head_pos - 1;
	if (j == -1)
		j = stk->a_len - 1;
	count = 1; //delete later
	while (j != head_pos)
	{
		if (stk->a[j] > stk->a[i])
		{
			mark[(stk->a)[j]] = KEEP;
			count++;
			i = j;
		}
		else
			mark[(stk->a)[j]] = OUT;
		j--;
		if (j == -1)
			j = stk->a_len - 1;
	}
	if (keep_nb != count)
	{
		printf("Error in mark!!!!!!!!!!!!!!\n");
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
	best_head = find_best_head_value(stk->a, stk->a_len, &best_keep_nb, &best_head_pos);
	printf("best_head=%d, is in position=%d, best_keep_nb=%d\n", best_head, best_head_pos, best_keep_nb);
	mark = do_mark(stk, best_head, best_head_pos, best_keep_nb);
	for (int i = 0; i < stk->a_len; ++i)
	{
		printf("mark[%d] == %d\n", i, mark[i]);
	}
	show_stack(stk, stk->a_len, stk->b_len);
	return (mark);
}

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


void	push_marked_in_a(t_stack *stk, int *mark, char flags, FILE *fp)
{
	int	out_nb;

	out_nb = nb_to_be_kicked_out(mark, stk->max_len);
	while (out_nb > 0)
	{
		while (mark[stk->a[stk->a_len - 1]] != OUT)
			ra(&stk, flags, fp);
		pb(&stk, flags, fp);
		out_nb--;
	}
}

void	optimised_insertion_algo(t_stack *stk, char flags, FILE *fp)
{
	int	*mark;

	printf("Init Stack\n");
	show_stack(stk, stk->a_len, stk->b_len);
	mark = mark_a(stk);
	push_marked_in_a(stk, mark, flags, fp);
}
