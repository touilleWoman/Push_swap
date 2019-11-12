/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:47:47 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/11 13:47:50 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_order(t_stack *stk, int tab_len)
{
	if (stk->b_len == 0 && stk->a_len == tab_len)
	{
		while (tab_len - 1)
		{
			if (stk->a[tab_len - 1] >= stk->a[tab_len - 2])
				break ;
			tab_len--;
		}
		tab_len == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	else
		ft_printf("KO\n");
}

void		usage_then_quit(void)
{
	ft_printf("Usage: ./checker [-v (optional):to show stack at every step]\n "
		"[a list of integer numbers seperated by space]\n");
	exit(0);
}

/*
** 	no need to free(stk->a), because stk->a == args
*/
void		free_all(t_stack *stk, t_list *ins_lst, int *args)
{
	free(stk->b);
	free(stk);
	free(args);
	free_list(ins_lst);
}

int			main(int argc, char const **argv)
{
	int		*args;
	t_list	*ins_lst;
	t_stack	*stk;
	char	flags;

	ins_lst = NULL;
	flags = 0;
	if (argc < 2)
		usage_then_quit();
	if (args_check(argc, argv) == FALSE)
		error_freelst_exit(ins_lst);
	args = parse_args(argc, argv, &flags);
	// if (args == NULL)
	// 	error_freelst_exit(ins_lst);
	if (parse_instructions(&ins_lst) == FALSE)
		error_freelst_exit(ins_lst);
	stk = execute_instructions(ins_lst, args, argc - 1);
	check_order(stk, argc - 1);
	free_all(stk, ins_lst, args);
	return (0);
}
