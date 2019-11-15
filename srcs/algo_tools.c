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

int		top1(t_stack *stk, char a_or_b)
{
	if (a_or_b == 'a')
		return (stk->a[stk->a_len - 1]);
	else if (a_or_b == 'b')
		return (stk->b[stk->b_len - 1]);
	else
	{
		ft_putendl_fd("ERROR parameter top1()", 2);
		return (-1);
	}
}

int		top2_exist(t_stack *stk, char a_or_b)
{
	if (a_or_b == 'a')
	{
		if (stk->a_len > 1)
			return (TRUE);
		return (FALSE);
	}
	else if (a_or_b == 'b')
	{
		if (stk->b_len > 1)
			return (TRUE);
		return (FALSE);
	}
	else
	{
		ft_putendl_fd("ERROR parameter top2()", 2);
		return (-1);
	}
}

int		top1_exist(t_stack *stk, char a_or_b)
{
	if (a_or_b == 'a')
	{
		if (stk->a_len > 0)
			return (TRUE);
		return (FALSE);
	}
	else if (a_or_b == 'b')
	{
		if (stk->b_len > 0)
			return (TRUE);
		return (FALSE);
	}
	else
	{
		ft_putendl_fd("ERROR parameter top2()", 2);
		return (-1);
	}
}

int		top2(t_stack *stk, char a_or_b)
{
	if (a_or_b == 'a')
		return (stk->a[stk->a_len - 2]);
	else if (a_or_b == 'b')
		return (stk->b[stk->b_len - 2]);
	else
	{
		ft_putendl_fd("ERROR parameter top2()", 2);
		return (-1);
	}
}

/*
** sort a increasing array
*/
void	increasing_tab_sort(int *tab, int tab_len)
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

int 	find_median(int *tab, int tab_len)
{
	int	i;
	int copy_tab[tab_len];

	i = 0;
	while (i < tab_len)
	{
		copy_tab[i] = tab[i];
		i++;
	}
	increasing_tab_sort(copy_tab, tab_len);
	if (tab_len % 2 == 0)
		return (copy_tab[tab_len / 2]);
	else
		return (copy_tab[(tab_len + 1) / 2]);
	// for(i=0 ; i<tab_len ; i++)
	//     printf("\ntab_1[%d] : %d",i,copy_tab[i]);
}


