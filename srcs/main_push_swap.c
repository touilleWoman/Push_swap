/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:28:03 by jleblond          #+#    #+#             */ /*   Updated: 2019/11/12 18:28:05 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** error_freelst_exit(), this functions is taken from checker, here it has no
**	list to free, so give NULL as parameter
*/

int main(int argc, char const **argv)
{
	int		*args;
	t_stack	*stk;
	char	flags;
	int		nb_args;

	flags = 0;
	nb_args = argc - 1;
	if (argc < 2)
		return (0);
	if (args_check(argc, argv) == FALSE)
		error_freelst_exit(NULL);
	args = parse_args_and_flags(argc, argv, &flags);
	if (args == NULL)
		error_freelst_exit(NULL);
	if (flags & V_FLAG)
		nb_args--;
	stk = launch_algo(args, argc, &flags);
	free_all(stk, NULL, args);
	return (0);
}
