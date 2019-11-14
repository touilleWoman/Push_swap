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

void		sa(t_stack **stk, char flags, FILE *fp, int *count)
{
	int		tmp;
	int		len;


	len = (*stk)->a_len;
	if (len > 1)
	{
		tmp = (*stk)->a[len - 1];
		(*stk)->a[len - 1] = (*stk)->a[len - 2];
		(*stk)->a[len - 2] = tmp;
	}
	print_according_to_flags(flags, fp, "sa\n", stk);
	(*count)++;
}

void		sb(t_stack **stk, char flags, FILE *fp, int *count)
{
	int		tmp;
	int		len;


	len = (*stk)->b_len;
	if (len > 1)
	{

		tmp = (*stk)->b[len - 1];
		(*stk)->b[len - 1] = (*stk)->b[len - 2];
		(*stk)->b[len - 2] = tmp;
	}
	print_according_to_flags(flags, fp, "sb\n", stk);
	(*count)++;
}

void		ss(t_stack **stk, char flags, FILE *fp, int *count)
{
	char flags_copy;

	flags_copy = flags;
	flags_copy -= INS_STDOUT;
	flags_copy -= V_FLAG;
	flags_copy -= F_FLAG;
	sa(stk, flags_copy, fp, count);
	sb(stk, flags_copy, fp, count);
	print_according_to_flags(flags, fp, "ss\n", stk);
	(*count)++;
}

void		pa(t_stack **stk, char flags, FILE *fp, int *count)
{

	if ((*stk)->b_len)
	{
		(*stk)->a_len++;
		(*stk)->a[(*stk)->a_len - 1] = (*stk)->b[(*stk)->b_len - 1];
		(*stk)->b_len--;
	}
	print_according_to_flags(flags, fp, "pa\n", stk);
	(*count)++;
}

void		pb(t_stack **stk, char flags, FILE *fp, int *count)
{

	if ((*stk)->a_len)
	{
		(*stk)->b_len++;
		(*stk)->b[(*stk)->b_len - 1] = (*stk)->a[(*stk)->a_len - 1];
		(*stk)->a_len--;
	}
	print_according_to_flags(flags, fp, "pb\n", stk);
	(*count)++;
}
