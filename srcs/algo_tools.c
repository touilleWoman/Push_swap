/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 06:45:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/15 06:45:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_an_increasing_tab(int *tab, int tab_len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = i + 1;
	tmp = 0;
	while (i < tab_len - 1)
	{
		while (j < tab_len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}





