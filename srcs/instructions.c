/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:47:52 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 15:47:54 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sa(t_stack **stk)
{
	int		tmp;
	int		len;

	len = (*stk)->a_len;
	if (len >= 2)
	{
		ft_printf("execute sa\n");
		tmp = (*stk)->a[len - 1];
		(*stk)->a[len - 1] = (*stk)->a[len - 2];
		(*stk)->a[len - 2] = tmp;
	}
}

void		sb(t_stack **stk)
{
	int		tmp;
	int		len;

	len = (*stk)->b_len;
	if (len >= 2)
	{
		ft_printf("execute sb\n");
		tmp = (*stk)->b[len - 1];
		(*stk)->b[len - 1] = (*stk)->b[len - 2];
		(*stk)->b[len - 2] = tmp;
	}
}

void		ss(t_stack **stk)
{
	ft_printf("execute ss\n");
	sa(stk);
	sb(stk);
}

void		pa(t_stack **stk)
{
	ft_printf("execute pa\n");
	if ((*stk)->b_len)
	{
		(*stk)->a_len++;
		(*stk)->a[(*stk)->a_len - 1] = (*stk)->b[(*stk)->b_len - 1];
		(*stk)->b_len--;
	}
}

void		pb(t_stack **stk)
{
	if ((*stk)->a_len)
	{
		ft_printf("execute pb\n");
		(*stk)->b_len++;
		(*stk)->b[(*stk)->b_len - 1] = (*stk)->a[(*stk)->a_len - 1];
		(*stk)->a_len--;
	}
}



