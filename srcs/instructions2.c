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

void		ra(t_stack **stk, char flags, FILE *fp)
{
	int		tmp;
	int		len;

	len = (*stk)->a_len;
	if (len > 1)
	{
		tmp = (*stk)->a[len - 1];
		while (len - 1)
		{
			(*stk)->a[len - 1] = (*stk)->a[len - 2];
			len--;
		}
		(*stk)->a[0] = tmp;
	}
	print_according_to_flags(flags, fp, "ra\n", stk);
	if (flags & COUNT)
		(*stk)->count++;
}

void		rb(t_stack **stk, char flags, FILE *fp)
{
	int		tmp;
	int		len;

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
	print_according_to_flags(flags, fp, "rb\n", stk);
	if (flags & COUNT)
		(*stk)->count++;
}

/*
** deactivate flags so information will not be printed again in ra and rb
** because ra and rb shouldn't be counted
** Same thing for ss and rrr.
*/

void		rr(t_stack **stk, char flags, FILE *fp)
{
	int		silence;

	silence = 0;
	ra(stk, 0, fp);
	rb(stk, 0, fp);
	print_according_to_flags(flags, fp, "rr\n", stk);
	if (flags & COUNT)
		(*stk)->count++;
}

void		rra(t_stack **stk, char flags, FILE *fp)
{
	int		tmp;
	int		len;
	int		i;

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
	print_according_to_flags(flags, fp, "rra\n", stk);
	if (flags & COUNT)
		(*stk)->count++;
}

void		rrb(t_stack **stk, char flags, FILE *fp)
{
	int		tmp;
	int		len;
	int		i;

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
	print_according_to_flags(flags, fp, "rrb\n", stk);
	if (flags & COUNT)
		(*stk)->count++;
}
