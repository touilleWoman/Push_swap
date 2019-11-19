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

t_stack			*init_stack_checker(int *args, int nb_int)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	ft_bzero(stk, sizeof(t_stack));
	stk->b = (int*)malloc(sizeof(int) * nb_int);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->a = args;
	stk->a_len = nb_int;
	stk->b_len = 0;
	return (stk);
}

t_stack			*init_stack_push_swap(int *int_array, int nb_int,
									int *origin_index, int *index)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	ft_bzero(stk, sizeof(t_stack));
	stk->b = (int*)malloc(sizeof(int) * nb_int);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->a = index;
	stk->a_len = nb_int;
	stk->b_len = 0;
	stk->max_len = nb_int;
	stk->count = 0;
	stk->origin_index = origin_index;
	stk->int_array = int_array;
	return (stk);
}

t_stack 	*copy_stack(t_stack *stk)
{
	t_stack	*cp;

	cp = (t_stack*)malloc(sizeof(t_stack));
	if (!cp)
		return (NULL);
	ft_memcpy(cp, stk, sizeof(t_stack));
	cp->a = (int*)malloc(sizeof(int) * stk->max_len);
	cp->b = (int*)malloc(sizeof(int) * stk->max_len);
	cp->origin_index = (int*)malloc(sizeof(int) * stk->max_len);
	cp->int_array = (int*)malloc(sizeof(int) * stk->max_len);
	if (!cp->a || !cp->b || !cp->origin_index || !cp->int_array)
	{
		free_push_swap_stack(cp);
		return (NULL);
	}
	ft_memcpy(cp->a, stk->a, sizeof(int) * stk->max_len);
	ft_memcpy(cp->b, stk->b, sizeof(int) * stk->max_len);
	ft_memcpy(cp->origin_index, stk->origin_index, sizeof(int) * stk->max_len);
	ft_memcpy(cp->int_array, stk->int_array, sizeof(int) * stk->max_len);
	return (cp);
}
