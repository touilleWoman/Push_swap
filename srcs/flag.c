/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:28:49 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/20 11:28:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_flag_string(char const *str)
{
	int		ret;

	ret = FALSE;
	if (ft_strcmp(str, "-v") == 0)
	{
		ret = TRUE;
	}
	else if (ft_strcmp(str, "-f") == 0)
	{
		ret = TRUE;
	}
	return (ret);
}

int			is_flag_then_activate(char const *str, char *flags)
{
	int		ret;

	ret = FALSE;
	if (ft_strcmp(str, "-v") == 0)
	{
		*flags = (*flags) | V_FLAG;
		ret = TRUE;
	}
	else if (ft_strcmp(str, "-f") == 0)
	{
		*flags = (*flags) | F_FLAG;
		ret = TRUE;
	}
	return (ret);
}

int			get_flags_nb_and_activate(int argc, char const **argv, char *flags)
{
	int		i;
	int		flag_nb;

	flag_nb = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag_then_activate(argv[i], flags))
			flag_nb++;
		i++;
	}
	return (flag_nb);
}
