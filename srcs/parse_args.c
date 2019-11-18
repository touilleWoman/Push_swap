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

/*
**	args_nb is the number of integers, not including flags.
**  Initialed as "argc -1", then it will change in args_check()
*/
int			*read_args_and_flags(int sstr_len, char **sstr, char *flags,
								int args_nb)
{
	int	i;
	int	j;
	int	*args;

	j = 0;
	i = args_nb - 1;
	args = (int*)malloc(sizeof(int) * args_nb);
	if (!args)
		return (NULL);
	while (j < sstr_len)
	{
		if (is_flag_then_activate(sstr[j], flags) == FALSE)
		{
			args[i] = ft_atoi(sstr[j]);
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

int			duplicate_args_exist(int *args, int args_nb)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (i < args_nb - 1)
	{
		while (j < args_nb)
		{
			if (args[i] == args[j])
				return (TRUE);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (FALSE);
}

int			args_check(int sstr_len, char **sstr, int *args_nb)
{
	int		i;

	i = 0;
	while (i < sstr_len)
	{
		if (ft_strcmp(sstr[i], "-v") == 0
			|| ft_strcmp(sstr[i], "-f") == 0)
			(*args_nb)--;
		else if (is_integer_string(sstr[i]) == FALSE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

char		**copy_argv_without_first(int sstr_len, char const **argv)
{
	char	**sstr;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	sstr = (char**)malloc(sizeof(char*) * (sstr_len + 1));
	if (!sstr)
		return (NULL);
	ft_memcpy(sstr, argv + 1, sizeof(char*) * len);
	sstr[sstr_len] = 0;
	while (i < sstr_len)
	{
		len = ft_strlen(argv[i + 1]);
		sstr[i] = (char*)malloc(sizeof(char) * (len + 1));
		if (!sstr[i])
		{	
			free_sstr(sstr, sstr_len);
			return (NULL);
		}
		ft_strcpy(sstr[i], argv[i + 1]);
		i++;
	}
	return (sstr);
}

void		free_sstr_and_exit(char **sstr, int sstr_len)
{
	ft_putendl_fd("Error", 2);
	free_sstr(sstr, sstr_len);
	exit(0);
}

int			*parse_args_and_flags(int argc, char const **argv,
									char *flags, int *args_nb)
{
	int		*args;
	char	**sstr;
	int		sstr_len;

	sstr_len = argc - 1;
	if (argc == 2)
	{
		sstr = ft_strsplit(argv[1], ' ');
		sstr_len = ft_strlen(sstr);
	}
	else
		sstr = copy_argv_without_first(sstr_len, argv);
	if (sstr == NULL)
		free_sstr_and_exit(sstr, sstr_len);
	int	n = 0;
	while (n < sstr_len)
	{
		ft_printf("%s\n", sstr[n]);
		n++;
	}
	*args_nb = sstr_len;
	if (args_check(sstr_len, sstr, args_nb) == FALSE)
		free_sstr_and_exit(sstr, sstr_len);
	args = read_args_and_flags(sstr_len, sstr, flags, *args_nb);
	if (args == NULL)
		free_sstr_and_exit(sstr, sstr_len);
	if (duplicate_args_exist(args, *args_nb))
	{
		free(args);
		free_sstr_and_exit(sstr, sstr_len);
	}
	free_sstr(sstr, sstr_len);
	return (args);
}
