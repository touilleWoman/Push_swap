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

void		rrr(t_stack **stk, char flags, FILE *fp)
{
	int		silence;

	silence = 0;
	rra(stk, 0, fp);
	rrb(stk, 0, fp);
	print_according_to_flags(flags, fp, "rrr\n", stk);
	if (flags & COUNT)
		(*stk)->count++;
}
