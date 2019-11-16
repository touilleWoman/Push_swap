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
** COUNT flag to count each instruction when activated
*/
void	read_flags_then_algo(t_stack *stk, char *flags)
{
	FILE		*fp;

	*flags = (*flags) | COUNT;
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
	algo(stk, *flags, fp);
	if ((*flags) & F_FLAG)
		fclose(fp);
}



int		*create_index_array_succeed(int *sorted, int *args, int nb_args)
{
	int		*index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	index = (int*)malloc(sizeof(int) * nb_args);
	if (!index)
		return (0);
	while (i < nb_args)
	{
		while (j < nb_args && args[i] != sorted[j])
			j++;
		index[i] = j;
		i++;
		j = 0;
	}
	return (index);
}

int 		*index_array_of_args(int *args, int nb_args)
{
	int sorted[nb_args];//change to malloc later???!!!
	int	*index;

	ft_memcpy(sorted, args, sizeof(int) * nb_args);
	sort_an_increasing_tab(sorted, nb_args);
	index = create_index_array_succeed(sorted, args, nb_args);
		return (index);
}

int			*copy_int_array(int	*tab, int tab_len)
{
	int		*ret;

	ret = (int*)malloc(sizeof(int) * tab_len);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, tab, sizeof(int) * tab_len);
	return (ret);
}



/*
** repalce args(list of integers) by a list of index,
** so it will be two stacks of indexs that we work on,
** it will be easier to do the algo on consecutive index then on args
** when coming to print results, with index, we can find the origin
** integer then print.
*/
t_stack		*launch_push_swap(int *args, char *flags, int nb_args)
{
	t_stack		*stk;
	int			*origin_index;
	int			*index;


	origin_index = index_array_of_args(args, nb_args); //remember free origin index!!!
	if (!origin_index)
		return (NULL);
	index = copy_int_array(origin_index, nb_args);
	if (!index)
		return (NULL);
	stk = init_stack_push_swap(args, nb_args, origin_index, index);
	if (stk == NULL)
	{
		ft_putendl_fd("Init stack failed!", 2);
		return (NULL);
	}
	// ft_printf("Inital score:%d\n", calculate_score(stk));
	read_flags_then_algo(stk, flags);
	return (stk);
}
