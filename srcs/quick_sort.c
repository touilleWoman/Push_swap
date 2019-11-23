/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:30:52 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/23 14:30:54 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	find_median(int *tab, int tab_len)
{
	int *copy_tab;
	int	median;

	copy_tab = copy_int_array(tab, tab_len);
	sort_an_increasing_tab(copy_tab, tab_len);
	if (tab_len % 2 != 0)
		median = copy_tab[tab_len / 2];
	else
		median = copy_tab[(tab_len - 1) / 2];
	free(copy_tab);
	return (median);
}


void	push_left_to_a(t_stack *stk, char flags, FILE *fp, int left)
{
	while (left > 0)
	{
		pa(&stk, flags, fp);
		left--;
	}
}

/*
** Ex: median stays in smaller stack(stack b)
*/




/*
** Ex: median gos to smaller stack(stack b)
** Ex: median of "0 1 2 3 4" is 2, b="0 1 2" , a = "3 4"
** Ex: median of "0 1 2 3 4 5" is also 2, b = "0 1 2" a="3 4 5"
*/



int		bigger_half_to_a(t_stack *stk, char flags, FILE *fp)
{
	int		to_a_nb;
	int		median;
	int		left;

	median = find_median(stk->b, stk->b_len);
	if (stk->b_len % 2 != 0)
		to_a_nb = stk->b_len / 2;
	else
		to_a_nb = stk->b_len / 2;
	left = stk->b_len - to_a_nb;
	printf("median of b:%d, to_a_nb:%d\n", median, to_a_nb);

	while (to_a_nb > 0)
	{
		while (stk->b[stk->b_len - 1] <= median)
			rb(&stk, flags, fp);
		pa(&stk, flags, fp);
		// if (stk->b_len > 1 && stk->b[stk->b_len - 1] > stk->b[stk->b_len - 2])
		// 	sa(&stk, flags, fp);
		to_a_nb--;
	}

	return (left);

}

void		smaller_half_to_b(t_stack *stk, char flags, FILE *fp, int n)
{
	int		to_b_nb;
	int		median;
	int		left;
	int		i;

	if (n == 1)
	{
		pb(&stk, flags, fp);
		rb(&stk, flags, fp);
		return ;
	}
	i = 0;
	median = find_median(stk->a, n);
	if (stk->a_len % 2 != 0)
		to_b_nb = stk->a_len / 2 + 1;
	else
		to_b_nb = stk->a_len / 2;
	left = stk->a_len - to_b_nb;
	printf("median:%d, to_b_nb:%d\n", median, to_b_nb);

	while (i < to_b_nb)
	{
		while (stk->a[stk->a_len - 1] > median)
			ra(&stk, flags, fp);
		pb(&stk, flags, fp);
		// if (stk->b_len > 1 && stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
		// 	sb(&stk, flags, fp);
		i++;
	}
	smaller_half_to_b(stk, flags, fp, left);

	push_left_to_a(stk, flags, fp, to_b_nb);

	smaller_half_to_b(stk, flags, fp, left);

}

void	quick_sort_algo(t_stack *stk, char flags, FILE *fp)
{
	smaller_half_to_b(stk, flags, fp, stk->max_len);


	ft_printf("quick_sort in total:%d\n", stk->count);
}
