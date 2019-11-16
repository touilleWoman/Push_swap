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



