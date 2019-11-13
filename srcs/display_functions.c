/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:49:22 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 19:49:25 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_args(int *args, int args_nb)
{
	int	i;

	i = args_nb - 1;
	while(i >= 0)
	{
		ft_printf("%d\n", args[i]);
		i--;
	}
}

void	print_lst(t_list *lst)
{
	int 	i = 0;
	while (lst != NULL)
	{
		ft_printf("%d eme elem of ins list:%d\n", i, *((int*)(lst->content)));
		lst = lst->next;
		i++;
	}
}

void		show_stack(t_stack *stk)
{
	int		max;
	int		i;
	int		j;

	i = stk->a_len;
	j = stk->b_len;
	max = (i > j ? i : j);
	while (max - 1 >= 0)
	{
		if (i == max && j == max)
			ft_printf("%d   %d\n", stk->a[max - 1], stk->b[max - 1]);
		else if (i == max && j != max)
			ft_printf("%d    \n", stk->a[max - 1]);
		else if (i != max && j == max)
			ft_printf("     %d\n", stk->b[max - 1]);
		i == max ? i-- : 0;
		j == max ? j-- : 0;
		max--;
	}
	ft_printf("-----\na   b\n");
}
