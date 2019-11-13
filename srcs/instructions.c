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

void		sa(t_stack **stk, char *flags)
{
	int		tmp;
	int		len;

	if ((*flags) & SHOW_INS)
		ft_printf("sa\n");
	len = (*stk)->a_len;
	if (len > 1)
	{
		tmp = (*stk)->a[len - 1];
		(*stk)->a[len - 1] = (*stk)->a[len - 2];
		(*stk)->a[len - 2] = tmp;

	}
	// else
	// {
	// 	if ((*flags) & SHOW_INS)
	// 		ft_printf("Pile a too short, sa not executed \n");
	// }
}

void		sb(t_stack **stk, char *flags)
{
	int		tmp;
	int		len;

	if ((*flags) & SHOW_INS)
		ft_printf("sb\n");
	len = (*stk)->b_len;
	if (len > 1)
	{

		tmp = (*stk)->b[len - 1];
		(*stk)->b[len - 1] = (*stk)->b[len - 2];
		(*stk)->b[len - 2] = tmp;
	}

}

void		ss(t_stack **stk, char *flags)
{
	if ((*flags) & SHOW_INS)
	{
		ft_printf("ss:\n");
		(*flags) -= SHOW_INS;
		sa(stk, flags);
		sb(stk, flags);
		(*flags) = (*flags) | SHOW_INS;
	}
	else
	{
		sa(stk, flags);
		sb(stk, flags);
	}
}

void		pa(t_stack **stk, char *flags)
{
	if ((*flags) & SHOW_INS)
		ft_printf("pa\n");
	if ((*stk)->b_len)
	{
		(*stk)->a_len++;
		(*stk)->a[(*stk)->a_len - 1] = (*stk)->b[(*stk)->b_len - 1];
		(*stk)->b_len--;

	}
	// else
	// {
	// 	if ((*flags) & SHOW_INS)
	// 		ft_printf("Pile b too short, pa not executed \n");
	// }
}

void		pb(t_stack **stk, char *flags)
{
	if ((*flags) & SHOW_INS)
		ft_printf("pb\n");
	if ((*stk)->a_len)
	{
		(*stk)->b_len++;
		(*stk)->b[(*stk)->b_len - 1] = (*stk)->a[(*stk)->a_len - 1];
		(*stk)->a_len--;

	}
	// else
	// {
	// 	if ((*flags) & SHOW_INS)
	// 		ft_printf("Pile a too short, pb not executed \n");
	// }
}
