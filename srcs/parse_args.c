/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:10:59 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/20 11:11:03 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			need_split(int argc, char const **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (is_flag_string(argv[i]) == FALSE
			&& is_space_separated_integer_string(argv[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char		**split_and_update_nb_int(char const **argv, int *nb_integer)
{
	int		i;
	char	**sstr;

	i = 1;
	while (argv[i])
	{
		if (is_flag_string(argv[i]) == FALSE)
		{
			sstr = ft_strsplit(argv[i], ' ');
		}
		i++;
	}
	i = 0;
	while (sstr[i] != NULL)
		i++;
	*nb_integer = i;
	return (sstr);
}

int			*convert_to_int_arry(char **sstr, int nb_int)
{
	int		i;
	int		j;
	int		*int_array;

	i = 0;
	j = nb_int - 1;
	int_array = (int*)malloc(sizeof(int) * nb_int);
	if (!int_array)
		return (NULL);
	while (i < nb_int)
	{
		if (is_integer_string(sstr[i]) == FALSE)
		{
			free(int_array);
			return (NULL);
		}
		int_array[j] = ft_atoi(sstr[i]);
		i++;
		j--;
	}
	return (int_array);
}

char		**copy_argv_without_flags(int nb_int, char const **argv)
{
	char	**sstr;
	int		i;
	int		j;

	i = 1;
	j = 0;
	sstr = (char**)malloc(sizeof(char*) * (nb_int + 1));
	if (!sstr)
		return (NULL);
	sstr[nb_int] = 0;
	while (argv[i])
	{
		if (is_flag_string(argv[i]) == FALSE)
		{
			sstr[j] = ft_strdup(argv[i]);
			if (!sstr[j])
			{
				free_sstr(sstr);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (sstr);
}

int			*parse_args_and_flags(int argc, char const **argv,
									char *flags, int *nb_int)
{
	int		*int_array;
	char	**sstr;
	int		flag_nb;

	flag_nb = get_flags_nb_and_activate(argc, argv, flags);
	*nb_int = argc - 1 - flag_nb;
	if (argc - flag_nb == 2 && need_split(argc, argv))
		sstr = split_and_update_nb_int(argv, nb_int);
	else
		sstr = copy_argv_without_flags(*nb_int, argv);
	int_array = convert_to_int_arry(sstr, *nb_int);
	if (int_array == NULL)
		free_sstr_and_exit(sstr);
	if (duplicate_int_exist(int_array, *nb_int))
	{
		free(int_array);
		free_sstr_and_exit(sstr);
	}
	free_sstr(sstr);
	return (int_array);
}
