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

static t_stack		*init_stack_checker(int *args, int nb_int)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	ft_bzero(stk, sizeof(t_stack));
	stk->b = (int*)malloc(sizeof(int) * nb_int);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->a = args;
	stk->a_len = nb_int;
	stk->b_len = 0;
	return (stk);
}

t_stack		*loop_instructions(t_list *ins_lst, t_stack *stk, char *flags)
{
	static t_funs	funs[INSTRUCTION_NB] =
	{{SA, sa}, {SB, sb}, {SS, ss}, {PA, pa}, {PB, pb}, {RA, ra}, {RB, rb},
	{RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	int				index;

	index = 0;
	if ((*flags) & V_FLAG)
	{
		ft_printf("Init stack:\n");
		show_stack(stk, stk->a_len, stk->b_len);
	}
	while (ins_lst != NULL)
	{
		while (index < INSTRUCTION_NB)
		{
			if (funs[index].ins == *(int*)(ins_lst->content))
				funs[index].f(&stk, *flags, NULL);
			index++;
		}
		ins_lst = ins_lst->next;
		index = 0;
	}
	return (stk);
}

t_stack		*execute_instructions(t_list *ins_lst, int *int_array,
										int nb_int, char *flags)
{
	t_stack	*stk;

	stk = init_stack_checker(int_array, nb_int);
	if (stk == NULL)
	{
		ft_putendl_fd("Init stack failed!", 2);
		return (NULL);
	}
	stk = loop_instructions(ins_lst, stk, flags);
	return (stk);
}
