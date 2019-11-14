/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_push_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:22:02 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/14 10:22:06 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



/*
** if F_FLAG present, write instruction on a file, otherwise activate
** INS_STDOUT flag to print on stdout
*/
void	read_flags_then_algo(t_stack *stk, int nb_args, char *flags)
{
	FILE		*fp;

	fp = NULL;
	if ((*flags) & F_FLAG)
	{
		fp = fopen("instructions", "w");
		if (fp == NULL)
		{
			ft_putendl_fd("Unable to create file!", 2);
			return ;
		}
	}
	else
		(*flags) = (*flags) | INS_STDOUT;
	algo(stk, nb_args, *flags, fp);
	if ((*flags) & F_FLAG)
		fclose(fp);
}

t_stack		*launch_push_swap(int *args, char *flags, int nb_args)
{
	t_stack		*stk;

	stk = init_stack(args, nb_args);
	if (stk == NULL)
	{
		ft_putendl_fd("Init stack failed!", 2);
		return (NULL);
	}
	read_flags_then_algo(stk, nb_args, flags);
	return (stk);
}
