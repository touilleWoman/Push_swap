/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:11:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 19:11:52 by jleblond         ###   ########.fr       */
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

void		free_sstr_and_exit(char **sstr)
{
	ft_putendl_fd("Error", 2);
	free_sstr(sstr);
	exit(0);
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
		if (is_integer_string(sstr[i]))
		{
			int_array[j] = ft_atoi(sstr[i]);
		}
		i++;
		j--;
	}
	return (int_array);
}

// int			*read_int_array(int sstr_len, char **sstr, char *flags,
// 								int nb_int)
// {
// 	int	i;
// 	int	j;
// 	int	*int_array;

// 	j = 0;
// 	i = nb_int - 1;
// 	int_array = (int*)malloc(sizeof(int) * nb_int);
// 	if (!int_array)
// 		return (NULL);
// 	while (j < sstr_len)
// 	{
// 		if (is_flag_then_activate(sstr[j], flags) == FALSE)
// 		{
// 			int_array[i] = ft_atoi(sstr[j]);
// 			i--;
// 		}
// 		j++;
// 	}
// 	if (i != -1)
// 	{
// 		ft_putendl_fd("Error in parser", 2);
// 		free(int_array);
// 		int_array = NULL;
// 	}
// 	return (int_array);
// }


char		**copy_argv_without_flags(int nb_int, char const **argv)
{
	char	**sstr;
	int		i;
	int		j;
	int		len;
	
	i = 1;
	len = 0;
	j = 0;
	sstr = (char**)malloc(sizeof(char*) * (nb_int + 1));
	if (!sstr)
		return (NULL);
	sstr[nb_int] = 0;
	while (argv[i])
	{
		if (is_flag_string(argv[i]) == FALSE)
		{
			len = ft_strlen(argv[i]);
			sstr[j] = (char*)malloc(sizeof(char) * (len + 1));
			if (!sstr[j])
			{	
				free_sstr(sstr);
				return (NULL);
			}
			ft_strcpy(sstr[j], argv[i]);
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
