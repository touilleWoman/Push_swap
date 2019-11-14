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

void		rb(t_stack **stk, char flags, FILE *fp, int *count)
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
	(*count)++;
}

/*
** deactivate flags so information will not be printed again in ra and rb
** Same thing for ss and rrr.
*/
void		rr(t_stack **stk, char flags, FILE *fp, int *count)
{
	char flags_copy;

	flags_copy = flags;
	flags_copy -= INS_STDOUT;
	flags_copy -= V_FLAG;
	flags_copy -= F_FLAG;
	ra(stk, flags_copy, fp, count);
	rb(stk, flags_copy, fp, count);
	print_according_to_flags(flags, fp, "rr\n", stk);
	(*count)++;
}

void		rra(t_stack **stk, char flags, FILE *fp, int *count)
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
	(*count)++;
}

void		rrb(t_stack **stk, char flags, FILE *fp, int *count)
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
	(*count)++;
}

void		rrr(t_stack **stk, char flags, FILE *fp, int *count)
{
	char flags_copy;

	flags_copy = flags;
	flags_copy -= INS_STDOUT;
	flags_copy -= V_FLAG;
	flags_copy -= F_FLAG;
	rra(stk, flags_copy, fp, count);
	rrb(stk, flags_copy, fp, count);
	print_according_to_flags(flags, fp, "rrr\n", stk);
	(*count)++;
}
