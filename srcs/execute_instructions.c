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

t_stack			*init_stack(int *args, int nb_args)
{
	t_stack		*stk;

	stk = (t_stack*)malloc(sizeof(t_stack));
	if (stk == NULL)
		return (NULL);
	stk->a = args;
	stk->a_len = nb_args;
	stk->b = (int*)malloc(sizeof(int) * nb_args);
	if (stk->b == NULL)
	{
		free(stk);
		return (NULL);
	}
	stk->b_len = 0;
	return (stk);
}

t_stack		*loop_instructions(t_list *ins_lst, t_stack *stk, char *flags)
{
	t_funs	funs[INSTRUCTION_NB] = {{SA, sa}, {SB, sb}, {SS, ss}, {PA, pa},
	{PB, pb}, {RA, ra}, {RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	int		index;
	int		count_ins;

	count_ins = 0;
	index = 0;
	if ((*flags) & V_FLAG)
	{
		ft_printf("Init stack:\n");
		show_stack(stk);
	}
	while (ins_lst != NULL)
	{
		while (index < INSTRUCTION_NB)
		{
			if (funs[index].ins == *(int*)(ins_lst->content))
			{
				funs[index].f(&stk, *flags, NULL, &count_ins);
				// (*flags) & V_FLAG ? show_stack(stk) : 0;
			}
			index++;
		}
		ins_lst = ins_lst->next;
		index = 0;
	}
	return (stk);
}

t_stack		*execute_instructions(t_list *ins_lst, int *args, int nb_args, char *flags)
{
	t_stack	*stk;

	stk = init_stack(args, nb_args);
	if (stk == NULL)
	{
		ft_putendl_fd("Init stack failed!", 2);
		return (NULL);
	}
	stk = loop_instructions(ins_lst, stk, flags);
	return (stk);
}
