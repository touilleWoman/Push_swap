/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:47:47 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/11 13:47:50 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		is_digit_string(const char *str)
{
	int	i;

	i = 0;
	while(str[i] != 0)
	{
		if (ft_isdigit(str[i]) == FALSE && str[i] != '-' && str[i] != '+')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		args_check(int argc, char const **argv)
{
	int	i;

	i = 0;
	while (i + 1 < argc)
	{
		if (ft_strlen(argv[i + 1]) > 11)
			return (FALSE);
		if (is_digit_string(argv[i + 1]) == FALSE)
			return (FALSE);
		//codes to add: check max int here
		i++;
	}
	return (TRUE);
}

int		*parse(int argc, char const **argv)
{
	int	*tab;
	int	i;
	int	j;

	tab = (int*)malloc(sizeof(int) * (argc - 1));
	if (tab == NULL)
		return (0);
	j = 1;
	i = argc - 2;
	while (i >= 0)
	{
		tab[i] = ft_atoi(argv[j]);
		i--;
		j++;
	}
	return (tab);

}

void	show_tab(int *tab, int tab_len)
{
	int	i;

	i = 0;
	while(i < tab_len)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
}

int		command_valid(char *s)
{
	if (ft_strcmp(s, "sa") == 0 || ft_strcmp(s, "sb") == 0 || ft_strcmp(s, "ss")
		== 0 || ft_strcmp(s, "pa")== 0 || ft_strcmp(s, "pb") == 0 || ft_strcmp(s, "ra")
		== 0 || ft_strcmp(s, "rb")== 0 || ft_strcmp(s, "rr")== 0 || ft_strcmp(s, "rra")
		== 0 || ft_strcmp(s, "rrb") == 0 || ft_strcmp(s, "rrr") == 0)
		return (TRUE);
	else
		return (FALSE);
}

int		read_command(char *commands)
{
	char *line;
	char space[2];

	space[0] = ' ';
	space[1] = 0;
	while (get_next_line(0, &line))
	{
		if (command_valid(line) == FALSE)
			return (FALSE);
		ft_strcat(commands, line);
		ft_strcat(commands, space);
	}
	return (TRUE);

}

int 	main(int argc, char const **argv)
{
	int		i;
	int		*tab;
	char	commands[1000]; //if commands too long???

	i = 0;
	if (argc >= 2 && args_check(argc, argv))
	{
		tab = parse(argc, argv);
		// show_tab(tab, argc - 1);
		if(read_command(commands) == FALSE)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		execute_commands(commands, tab, argc - 1);
		// ft_printf("%s", commands);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}
