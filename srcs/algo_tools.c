/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 06:45:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/15 06:45:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_an_increasing_tab(int *tab, int tab_len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = i + 1;
	tmp = 0;
	while (i < tab_len - 1)
	{
		while (j < tab_len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
		j = i + 1;
	}
}

int			*copy_int_array(int *tab, int tab_len)
{
	int		*ret;

	ret = (int*)malloc(sizeof(int) * tab_len);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, tab, sizeof(int) * tab_len);
	return (ret);
}

int			find_int_from_index_dict(int *int_array, int *index,
										int elem_index, int nb_int)
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
