/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:48:21 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 17:48:23 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		ra(t_stack **stk, char flags, FILE *fp, int *count)
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
	(*count)++;
}
