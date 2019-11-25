/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 08:09:17 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/25 08:09:19 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		last_in_color(t_stack *stk)
{
	int score;

	score = calculate_score(stk);
	if (score == 0)
		ft_printf("\033[0;31m");
}
