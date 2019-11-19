/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:49:22 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 19:49:25 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_list *lst)
{
	int 	i = 0;
	while (lst != NULL)
	{
		ft_printf("%d eme elem of ins list:%d\n", i, *((int*)(lst->content)));
		lst = lst->next;
		i++;
	}
}

void		show_stack(t_stack *stk)
{
	int		max;
	int		i;
	int		j;

	i = stk->a_len;
	j = stk->b_len;
	max = (i > j ? i : j);
	while (max - 1 >= 0)
	{
		if (i == max && j == max)
			ft_printf("%d   %d\n", stk->a[max - 1], stk->b[max - 1]);
		else if (i == max && j != max)
			ft_printf("%d    \n", stk->a[max - 1]);
		else if (i != max && j == max)
			ft_printf("     %d\n", stk->b[max - 1]);
		i == max ? i-- : 0;
		j == max ? j-- : 0;
		max--;
	}
	ft_printf("-----\na   b\n");
}

/*
** find original integer with index
*/
int			int_array_index_dictionary(int *int_array, int *index, int elem_index, int nb_int)
{
	int		i;

	i = 0;
	while (i < nb_int)
	{
		if (index[i] == elem_index)
		{
			return (int_array[i]);
		}
		i++;
	}
	ft_putendl_fd("Error, can't find integer in dictionary\n", 2);
	return (0);
}

void		show_stack_with_index_stack(t_stack *s)
{
	int		max;
	int		i;
	int		j;
	int		elem_a;
	int		elem_b;

	elem_a = 0;
	elem_b = 0;
	i = s->a_len;
	j = s->b_len;
	max = (i > j ? i : j);
	while (max - 1 >= 0)
	{
		if (i == max && j == max)
		{
			elem_a = int_array_index_dictionary(s->int_array, s->origin_index, s->a[max - 1], s->max_len);
			elem_b = int_array_index_dictionary(s->int_array, s->origin_index, s->b[max - 1], s->max_len);
			ft_printf("%d   %d\n", elem_a, elem_b);
			// ft_printf("%d   %d\n", s->a[max - 1], s->b[max - 1]);
		}
		else if (i == max && j != max)
		{
			elem_a = int_array_index_dictionary(s->int_array, s->origin_index, s->a[max - 1], s->max_len);
			ft_printf("%d    \n", elem_a);
			// ft_printf("%d    \n", s->a[max - 1]);
		}
		else if (i != max && j == max)
		{
			elem_b = int_array_index_dictionary(s->int_array, s->origin_index, s->b[max - 1], s->max_len);
			ft_printf("     %d\n", elem_b);
		}
		i == max ? i-- : 0;
		j == max ? j-- : 0;
		max--;
	}
	ft_printf("-----\na   b\n");
}



/*
** fputs() allows to write on a file, it should be used only when F_FLAG present,
** and only in push_wap, not in checker
*/
void		print_according_to_flags(char flags, FILE *fp, char *str,
									t_stack **stk)
{
	if (flags & INS_STDOUT)
		ft_printf(str);
	else if ((flags & F_FLAG) && (flags & PUSH_SWAP))
		fputs(str, fp);
	if ((flags & V_FLAG) && ((flags & PUSH_SWAP) == 0))
		show_stack(*stk);
	if ((flags & V_FLAG) && (flags & PUSH_SWAP))
		show_stack_with_index_stack(*stk);
}
