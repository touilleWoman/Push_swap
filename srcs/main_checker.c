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

void		check_order(t_stack *stk, int nb_args)
{
	if (stk->b_len == 0 && stk->a_len == nb_args)
	{
		while (nb_args - 1)
		{
			if (stk->a[nb_args - 1] > stk->a[nb_args - 2])
				break ;
			nb_args--;
		}
		nb_args == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
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

int			main(int argc, char const **argv)
{
	int		*args;
	t_list	*ins_lst;
	t_stack	*stk;
	char	flags;
	int		nb_args;

	ins_lst = NULL;
	flags = 0;
	nb_args = argc - 1;
	if (argc < 2)
		usage_then_quit();
	args = parse_args_and_flags(argc, argv, &flags, &nb_args);
	if (parse_instructions(&ins_lst) == FALSE)
		error_freelst_exit(ins_lst);
	stk = execute_instructions(ins_lst, args, nb_args, &flags);
	check_order(stk, nb_args);
	free_all(stk, ins_lst, args);
	return (0);
}
