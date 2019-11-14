/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 10:02:14 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/14 10:02:17 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	a_to_long(const char *str)
{
	int				i;
	long long		ret;
	int				neg;

	neg = 1;
	i = 0;
	ret = 0;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while ((str[i] != 0) && (str[i] >= '0') && (str[i] <= '9'))
	{
		ret = ret * 10 + str[i] - '0';
		i++;
	}
	return (ret * neg);
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