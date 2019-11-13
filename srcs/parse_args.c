/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:11:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 19:11:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long		a_to_long(const char *str)
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

int				is_integer_string(const char *str)
{
	int			i;
	int			len;
	long long	nb_long;

	i = 0;
	len = ft_strlen(str);
	if (len > 11)
		return (FALSE);
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while(i < len)
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

int				args_check(int argc, char const **argv)
{
	int		i;

	i = 0;

	while (i + 1 < argc)
	{
		if (is_integer_string(argv[i + 1]) == FALSE
			&& ft_strcmp(argv[i + 1], "-v"))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		*parse_args_and_flags(int argc, char const **argv, char *flags)
{
	int	*tab;
	int	i;
	int	j;
	int	args_nb;

	args_nb = argc - 1;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		*flags = (*flags) | V_FLAG;
		args_nb--;
	}
	tab = (int*)malloc(sizeof(int) * args_nb);
	if (!tab)
		return (0);
	j = argc - args_nb;
	i = args_nb - 1;
	while (i >= 0)
	{
		tab[i] = ft_atoi(argv[j]);
		i--;
		j++;
	}
	return (tab);
}

void	error_freelst_exit(t_list *lst)
{
	ft_putendl_fd("Error", 2);
	if (lst != NULL)
		free_list(lst);
	exit(0);
}
