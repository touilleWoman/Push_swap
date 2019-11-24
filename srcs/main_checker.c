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

void		check_order(t_stack *stk, int nb_int)
{
	if (stk->b_len == 0 && stk->a_len == nb_int)
	{
		while (nb_int - 1)
		{
			if (stk->a[nb_int - 1] > stk->a[nb_int - 2])
				break ;
			nb_int--;
		}
		nb_int - 1 == 0 ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	else
		ft_printf("KO\n");
}


/*
** no need to free stk->a, because stk->a is int_array.
*/

void		free_all(t_stack *stk, t_list *ins_lst, int *int_array)
{
	if (stk != NULL)
	{
		stk->b != NULL ? free(stk->b) : 0;
		free(stk);
		stk = NULL;
	}
	ins_lst != NULL ? free_list(ins_lst) : 0;
	int_array != NULL ? free(int_array) : 0;
}

void		error_and_exit(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int			main(int argc, char const **argv)
{
	int		*int_array;
	t_list	*ins_lst;
	t_stack	*stk;
	char	flags;
	int		nb_int;

	ins_lst = NULL;
	flags = 0;
	nb_int = 0;
	stk = NULL;
	argc < 2 ? exit (0) : 0;
	int_array = parse_args_and_flags(argc, argv, &flags, &nb_int);
	if (int_array == NULL)
		error_and_exit();
	if (parse_instructions(&ins_lst, flags) == FALSE)
	{
		free_all(NULL, ins_lst, int_array);
		ft_putendl_fd("Error", 2);
		return (0);
	}
	stk = execute_instructions(ins_lst, int_array, nb_int, &flags);
	check_order(stk, nb_int);
	free_all(stk, ins_lst, int_array);
	return (0);
}
