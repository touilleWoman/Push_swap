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

/*
** find original integer with index
*/

void		print_one_line(int elem_a, int elem_b,
						t_bool a_exist, t_bool b_exist)
{
	char	str[30];
	char	*a;
	char	*b;

	ft_memset(str, ' ', 29);
	str[29] = 0;
	if (a_exist)
	{
		a = ft_itoa(elem_a);
		ft_memcpy(str, a, sizeof(char) * ft_strlen(a));
		free(a);
	}
	if (b_exist)
	{
		b = ft_itoa(elem_b);
		ft_memcpy(str + 14, b, sizeof(char) * ft_strlen(b));
		free(b);
	}
	ft_printf("%s\n", str);
}

int			get_a(t_stack *s, int position, t_bool *a_exist)
{
	int		elem_a;

	elem_a = find_int_from_index_dict(s->int_array, s->origin_index,
										s->a[position], s->max_len);
	*a_exist = TRUE;
	return (elem_a);
}

int			get_b(t_stack *s, int position, t_bool *b_exist)
{
	int		elem_b;

	elem_b = find_int_from_index_dict(s->int_array, s->origin_index,
										s->b[position], s->max_len);
	*b_exist = TRUE;
	return (elem_b);
}

void		show_stack_with_index_stack(t_stack *s, int a_len, int b_len)
{
	int		max;
	int		elem_a;
	int		elem_b;
	t_bool	a_exist;
	t_bool	b_exist;

	elem_a = 0;
	elem_b = 0;
	a_exist = FALSE;
	b_exist = FALSE;
	max = (a_len > b_len ? a_len : b_len);
	while (max - 1 >= 0)
	{
		if (a_len == max)
			elem_a = get_a(s, max - 1, &a_exist);
		if (b_len == max)
			elem_b = get_b(s, max - 1, &b_exist);
		print_one_line(elem_a, elem_b, a_exist, b_exist);
		a_len == max ? a_len-- : 0;
		b_len == max ? b_len-- : 0;
		max--;
	}
	ft_printf("-----------------------------\na              b\n\n");
}

/*
** fputs() allows to write on a file,
** it should be used only when F_FLAG present,
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
		show_stack_with_index_stack(*stk, (*stk)->a_len, (*stk)->b_len);
}
