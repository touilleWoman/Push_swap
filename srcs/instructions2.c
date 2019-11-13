/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:23:40 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 16:23:42 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		rb(t_stack **stk, char *flags)
{
	int		tmp;
	int		len;

	if ((*flags) & SHOW_INS)
		ft_printf("rb\n");
	len = (*stk)->b_len;
	if (len > 1)
	{
		tmp = (*stk)->b[len - 1];
		while (len - 1)
		{
			(*stk)->b[len - 1] = (*stk)->b[len - 2];
			len--;
		}
		(*stk)->b[0] = tmp;
	}
	// else
	// {
	// 	if ((*flags) & SHOW_INS)
	// 		ft_printf("Pile b too short, rb not executed \n");
	// }

}

/*
** if flag SHOW_INS activated, I want to print "rr", then not print "ra" and "rb"
** I need to deactivate the flag SHOW_INS, do ra rab, then reactivate the flag
** Same thing for ss and rrr.
*/
void		rr(t_stack **stk, char *flags)
{
	if ((*flags) & SHOW_INS)
	{
		ft_printf("rr\n");
		(*flags) -= SHOW_INS;
		ra(stk, flags);
		rb(stk, flags);
		(*flags) = (*flags) | SHOW_INS;
	}
	else
	{
		ra(stk, flags);
		rb(stk, flags);
	}
}

void		rra(t_stack **stk, char *flags)
{
	int		tmp;
	int		len;
	int		i;

	if ((*flags) & SHOW_INS)
		ft_printf("rra\n");
	i = 0;
	len = (*stk)->a_len;
	if (len > 1)
	{
		tmp = (*stk)->a[0];
		while (i < len - 1)
		{
			(*stk)->a[i] = (*stk)->a[i + 1];
			i++;
		}
		(*stk)->a[len - 1] = tmp;

	}
	// else
	// {
	// 	if ((*flags) & SHOW_INS)
	// 		ft_printf("Pile a too short, rra not executed \n");
	// }
}

void		rrb(t_stack **stk, char *flags)
{
	int		tmp;
	int		len;
	int		i;

	if ((*flags) & SHOW_INS)
		ft_printf("rrb\n");
	i = 0;
	len = (*stk)->b_len;
	if (len > 1)
	{
		tmp = (*stk)->b[0];
		while (i < len - 1)
		{
			(*stk)->b[i] = (*stk)->b[i + 1];
			i++;
		}
		(*stk)->b[len - 1] = tmp;

	}
	// else
	// {
	// 	if ((*flags) & SHOW_INS)
	// 		ft_printf("Pile b too short, rrb not executed \n");
	// }
}

void		rrr(t_stack **stk, char *flags)
{
	if ((*flags) & SHOW_INS)
	{
		ft_printf("rrr\n");
		(*flags) -= SHOW_INS;
		rra(stk, flags);
		rrb(stk, flags);
		(*flags) = (*flags) | SHOW_INS;
	}
	else
	{
		rra(stk, flags);
		rrb(stk, flags);
	}
}
