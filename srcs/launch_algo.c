/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:35:51 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/13 17:36:03 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		in_right_order(t_stack *stk, int nb_args)
{
	int		count;

	count = nb_args - 1;
	if (stk->b_len == 0 && stk->a_len == nb_args)
	{
		while (count)
		{
			if (stk->a[count] > stk->a[count - 1])
				break ;
			count--;
		}
		if (count == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

void	one_round(t_stack *stk, char *flags)
{
	while (stk->a_len > 1)
	{
		while (stk->a[stk->a_len - 1] > stk->a[stk->a_len - 2])
			ra(&stk, flags);
		pb(&stk, flags);
		if (stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
			sb(&stk, flags);
	}
	while (stk->b_len > 1)
	{
		while (stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
			rb(&stk, flags);
		pa(&stk, flags);
		if (stk->a[stk->a_len - 1] > stk->a[stk->a_len - 2])
			sa(&stk, flags);
	}
	pa(&stk, flags);
}

void	algo(t_stack *stk, int nb_args, char *flags)
{
	while (in_right_order(stk, nb_args) == FALSE)
		one_round(stk, flags);
}

/*
** activate SHOW_INS flag to print each instruction executed on stdout
*/

t_stack		*launch_algo(int *args, int argc, char *flags)
{
	t_stack		*stk;
	int			nb_args;

	(*flags) = (*flags) | SHOW_INS;
	nb_args = argc - 1;
	if ((*flags) & V_FLAG)
		nb_args--;
	stk = init_stack(args, nb_args);
	if (stk == NULL)
	{
		ft_putendl_fd("Init stack failed!", 2);
		return (NULL);
	}
	algo(stk, nb_args, flags);
	return (stk);
}
