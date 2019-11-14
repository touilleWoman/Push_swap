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

int				args_check(int argc, char const **argv, int *args_nb)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-v") == 0
			|| ft_strcmp(argv[i], "-f") == 0)
			(*args_nb)--;
		else if (is_integer_string(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}


int				is_flag(char const *str, char *flags)
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

/*
**	args_nb is the number of integers, not including flags.
**  Initialed "argc -1", then will change in args_check()
*/

int				*read_args_and_flags(int argc, char const **argv, char *flags,
									 int args_nb)
{
	int	i;
	int	j;
	int	*args;

	j = 1;
	i = args_nb - 1;
	args = (int*)malloc(sizeof(int) * args_nb);
	if (!args)
		return (NULL);
	while (j < argc)
	{
		if (is_flag(argv[j], flags) == FALSE)
		{
			args[i] = ft_atoi(argv[j]);
			i--;
		}
		j++;
	}
	if (i != -1)
	{
		ft_putendl_fd("Error in parser", 2);
		free(args);
		args = NULL;
	}
	return (args);
}

int				*parse_args_and_flags(int argc,
									char const **argv,
									char *flags)
{
	int	*args;
	int	args_nb;

	args_nb = argc - 1;
	if (args_check(argc, argv, &args_nb) == FALSE)
		return (NULL);
	args = read_args_and_flags(argc, argv, flags, args_nb);
	if (args == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	return (args);
}

