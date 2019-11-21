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

FILE		*get_fp_from_input(void)
{
	char		filename[100];
	int			len;
	FILE		*fp;

	fp = NULL;
	len = 0;
	ft_printf("Pleases give the path of file:\n");
	if (fgets(filename, 50, stdin))
	{
		len = ft_strlen(filename);
		(filename[len - 1] == '\n') ? filename[len - 1] = 0 : 0;
		fp = fopen(filename, "w");
		if (fp == NULL)
			ft_putendl_fd("fopen failed!", 2);
	}
	return (fp);
}

void		read_flags_then_choose_algo(t_stack *stk, char *flags)
{
	FILE		*fp;

	*flags = (*flags) | COUNT;
	fp = NULL;
	if ((*flags) & F_FLAG)
	{
		fp = get_fp_from_input();
		if (fp == NULL)
			return ;
	}
	else
		(*flags) = (*flags) | INS_STDOUT;
	choose_algo(stk, *flags, fp);
	if (fp)
		fclose(fp);
}

int			*create_index_array(int *sorted, int *args, int nb_int)
{
	int		*index;
	int		i;
	int		j;

	i = 0;
	j = 0;
	index = (int*)malloc(sizeof(int) * nb_int);
	if (!index)
		return (0);
	while (i < nb_int)
	{
		while (j < nb_int && args[i] != sorted[j])
			j++;
		index[i] = j;
		i++;
		j = 0;
	}
	return (index);
}

int			*index_array_of_args(int *int_array, int nb_int)
{
	int *sorted;
	int	*index;

	sorted = (int*)malloc(sizeof(int) * nb_int);
	if (!sorted)
		return (NULL);
	ft_memcpy(sorted, int_array, sizeof(int) * nb_int);
	sort_an_increasing_tab(sorted, nb_int);
	index = create_index_array(sorted, int_array, nb_int);
	free(sorted);
	return (index);
}

/*
** repalce int_array(list of integers) by an array of index,
** so it will be two stacks of indexs that we work on,
** it will be easier to do the algo on consecutive index int
** then on a list of integers
** when it comes to printing results, with index, we can find the origin
** integer then print.
*/

t_stack		*launch_push_swap(int *int_array, char *flags, int nb_int)
{
	t_stack		*stk;
	int			*origin_index;
	int			*index;

	origin_index = index_array_of_args(int_array, nb_int);
	if (!origin_index)
		return (NULL);
	index = copy_int_array(origin_index, nb_int);
	if (!index)
	{
		free(origin_index);
		return (NULL);
	}
	stk = init_stack_push_swap(int_array, nb_int, origin_index, index);
	if (stk == NULL)
	{
		ft_putendl_fd("Init stack failed!", 2);
		return (stk);
	}
	read_flags_then_choose_algo(stk, flags);
	return (stk);
}
