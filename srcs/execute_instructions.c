/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:29:25 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 15:29:28 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			init_stack_succeed(int *tab, int tab_len, t_stack **stk)
{
	*stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (FALSE);
	(*stk)->a = tab;
	(*stk)->a_len = tab_len;
	(*stk)->b = (int*)malloc(sizeof(int) * tab_len);
	if ((*stk)->b == NULL)
		return (FALSE);
	(*stk)->b_len = 0;
	return (TRUE);
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




t_stack		*execute_instructions(t_list *ins_lst, int *tab, int tab_len)
{
	t_stack	*stk;
	// t_funs	funs[INSTRUCTION_NB] = {{SA, sa}, {SB, sb}
	t_funs	funs[4] = {{SA, sa}, {SB, sb}, {PA, pa}, {PB, pb}};
	int		index;


	index = 0;
	if (init_stack_succeed(tab, tab_len, &stk))
	{
		ft_printf("original stack:\n");
		show_stack(stk);
		while (ins_lst != NULL)
		{
			while (index < 4)
			{
				if (funs[index].ins == *(int*)(ins_lst->content))
				{
					funs[index].f(&stk);
					show_stack(stk);
				}
				index++;
			}
			ins_lst = ins_lst->next;
			index = 0;
		}

	}
	else
		ft_printf("cant init stack");
	return (stk);

}
