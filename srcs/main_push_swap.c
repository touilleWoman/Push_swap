/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 06:40:15 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/15 06:40:18 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
** int_array are the list of integers that we read from stdin or a file,
** after excluding flags
*/
int main(int argc, char const **argv)
{
	int		*int_array;
	t_stack	*stk;
	char	flags;
	int		nb_int;

	flags = 0;
	nb_int = 0;
	if (argc < 2)
		return (0);
	flags = flags | PUSH_SWAP;
	int_array = parse_args_and_flags(argc, argv, &flags, &nb_int);
	if (int_array == NULL)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	stk = launch_push_swap(int_array, &flags, nb_int);
	free_push_swap_stack(stk);
	return (0);
}
