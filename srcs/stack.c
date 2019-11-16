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

void	free_push_swap_stack(t_stack *stk)
{
	if (stk != NULL)
	{
		stk->b != NULL ? free(stk->b) : 0;
		stk->a != NULL ? free(stk->a) : 0;
		stk->origin_index != NULL ? free(stk->origin_index) : 0;
		stk->args != NULL ? free(stk->args) : 0;
		stk->b = NULL;
		stk->a = NULL;
		stk->origin_index = NULL;
		stk->args = NULL;
		free(stk);
		stk = NULL;
	}
}

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
	cp->args = (int*)malloc(sizeof(int) * stk->max_len);
	if (!cp->a || !cp->b || !cp->origin_index || !cp->args)
	{
		free_push_swap_stack(cp);
		return (NULL);
	}
	ft_memcpy(cp->a, stk->a, sizeof(int) * stk->max_len);
	ft_memcpy(cp->b, stk->b, sizeof(int) * stk->max_len);
	ft_memcpy(cp->origin_index, stk->origin_index, sizeof(int) * stk->max_len);
	ft_memcpy(cp->args, stk->args, sizeof(int) * stk->max_len);
	return (cp);
}
