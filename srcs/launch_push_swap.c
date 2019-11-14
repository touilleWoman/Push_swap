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

int		in_right_order(t_stack *stk, int nb_args)
{
	int		count;

	count = nb_args - 1;
	if (stk->b_len == 0 && stk->a_len == nb_args)
	{
		while (count)
		{
			if (stk->a[count] > stk->a[count - 1])
				break ;
			count--;
		}
		if (count == 0)
			return (TRUE);
		else
			return (FALSE);
	}
	else
		return (FALSE);
}

void	one_round(t_stack *stk, char flags, FILE *fp, int *count)
{
	while (stk->a_len > 1)
	{
		while (stk->a[stk->a_len - 1] > stk->a[stk->a_len - 2])
			ra(&stk, flags, fp, count);
		pb(&stk, flags, fp, count);
		if (stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
			sb(&stk, flags, fp, count);
	}
	while (stk->b_len > 1)
	{
		while (stk->b[stk->b_len - 1] < stk->b[stk->b_len - 2])
			rb(&stk, flags, fp, count);
		pa(&stk, flags, fp, count);
		if (stk->a[stk->a_len - 1] > stk->a[stk->a_len - 2])
			sa(&stk, flags, fp, count);
	}
	pa(&stk, flags, fp, count);
}

void	algo(t_stack *stk, int nb_args, char flags, FILE *fp)
{
	int		count;

	count = 0;
	while (in_right_order(stk, nb_args) == FALSE)
		one_round(stk, flags, fp, &count);
}

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
