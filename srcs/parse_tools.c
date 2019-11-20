/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:24:18 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/20 11:24:21 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			duplicate_int_exist(int *int_array, int nb_int)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (i < nb_int - 1)
	{
		while (j < nb_int)
		{
			if (int_array[i] == int_array[j])
				return (TRUE);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (FALSE);
}

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

int			is_integer_string(const char *str)
{
	int			i;
	int			len;
	long long	nb_long;

	i = 0;
	len = ft_strlen(str);
	if (len > 11)
		return (FALSE);
	if (str[i] == '-')
		i++;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	if (len == 11 || len == 10)
	{
		nb_long = a_to_long(str);
		if (nb_long > 2147483647 || nb_long < -2147483648)
			return (FALSE);
	}
	return (TRUE);
}

int			is_space_separated_integer_string(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if ((str[i] != ' ') && (str[i] != '-')
			&& ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
