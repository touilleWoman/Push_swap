/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:13:04 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/16 12:13:06 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack			*init_stack_checker(int *args, int nb_args)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	ft_bzero(stk, sizeof(t_stack));
	stk->b = (int*)malloc(sizeof(int) * nb_args);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->a = args;
	stk->a_len = nb_args;
	stk->b_len = 0;
	return (stk);
}

t_stack			*init_stack_push_swap(int *args, int nb_args,
									int *origin_index, int *index)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	ft_bzero(stk, sizeof(t_stack));
	stk->b = (int*)malloc(sizeof(int) * nb_args);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->a = index;
	stk->a_len = nb_args;
	stk->b_len = 0;
	stk->max_len = nb_args;
	stk->count = 0;
	stk->origin_index = origin_index;
	stk->args = args;
	return (stk);
}