// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   score_algo.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/11/20 14:23:41 by jleblond          #+#    #+#             */
// /*   Updated: 2019/11/20 14:23:42 by jleblond         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "push_swap.h"



// void	push_to_b(t_stack *stk, char flags, FILE *fp)
// {
// 	int		median;
// 	int		to_b_nb;

// 	median = stk->max_len / 2;
// 	if (stk->max_len % 2 == 0)
// 		to_b_nb = median;
// 	else
// 		to_b_nb = median + 1;
// 	while (to_b_nb > 0)
// 	{
// 		while (stk->a[stk->a_len - 1] > median && to_b_nb > 0)
// 		{
// 			ra(&stk, flags, fp);
// 			// printf("Inside median:%d, to_b_nb:%d\n", median, to_b_nb);
// 		}
// 		// printf("median:%d, to_b_nb:%d\n", median, to_b_nb);
// 		pb(&stk, flags, fp);
// 		to_b_nb--;
// 	}
// }

// void	push_back_to_a(t_stack *stk, char flags, FILE *fp)
// {
// 	int		median;

// 	median = stk->max_len / 2;
// 	while (stk->a_len < stk->max_len - 1)
// 	{
// 		pa(&stk, flags, fp);
// 		*min_score = execute_if_score_smaler(stk, flags, fp);
// 	}
// }

// int		best_score_algo(t_stack *stk, char flags, FILE *fp, int last_algo_nb)
// {
// 	int		min_score;
// 	int		i;

// 	(void)last_algo_nb;
// 	i = 0;
// 	min_score = execute_if_score_smaler(stk, flags, fp);
// 	if (min_score)
// 	{
// 		push_to_b(stk, flags, fp);
// 		execute_if_score_smaler(stk, flags, fp)
// 		push_back_to_a(stk, flags, fp, &min_score);
// 	}
// 	min_score = execute_if_score_smaler(stk, flags, fp);

// 	while (stk->a_len != stk->max_len)
// 		pa(&stk, flags, fp);
// 	ft_printf("best score in total:%d\n", stk->count);
// 	return (stk->count);
// }
