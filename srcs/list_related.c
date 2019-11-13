/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_related.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:54:58 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 19:55:05 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

/*
** 	no need to free(stk->a), because stk->a == args
*/
void		free_all(t_stack *stk, t_list *ins_lst, int *args)
{
	if (stk != NULL)
	{
		stk->b != NULL ? free(stk->b) : 0;
		free(stk);
	}
	args != NULL ? free(args) : 0;
	ins_lst != NULL ? free_list(ins_lst) : 0;
}

void	error_freelst_exit(t_list *lst)
{
	ft_putendl_fd("Error", 2);
	if (lst != NULL)
		free_list(lst);
	exit(0);
}