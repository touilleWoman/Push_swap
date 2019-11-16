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

t_stack			*init_stack(int *args, int nb_args)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	stk->b = (int*)malloc(sizeof(int) * nb_args);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->a = args;
	stk->a_len = nb_args;
	stk->b_len = 0;
	stk->max_len = nb_args;
	stk->count = 0;
	return (stk);
}