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

int		*parse_args(int argc, char const **argv)
{
	int	*tab;
	int	i;
	int	j;

	tab = (int*)malloc(sizeof(int) * (argc - 1));
	if (!tab)
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

void		check_instruction_then_convert(char *s, t_instruction *ins)
{
	*ins = ERROR;
	if (s[0] == 's')
	{
		(s[1] == 'a' && s[2] == 0) ? (*ins = SA) : 0;
		(s[1] == 'b' && s[2] == 0) ? (*ins = SB) : 0;
	}
	else if (s[0] == 'p')
	{
		(s[1] == 'a' && s[2] == 0) ? (*ins = PA) : 0;
		(s[1] == 'b' && s[2] == 0) ? (*ins = PB) : 0;
	}
	else if (s[0] == 'r')
	{
		(s[1] == 'a' && s[2] == 0) ? (*ins = RA) : 0;
		(s[1] == 'b' && s[2] == 0) ? (*ins = RB) : 0;
		(s[1] == 'r' && s[2] == 0) ? (*ins = RR) : 0;
		(s[1] == 'r' && s[2] == 'a' && s[3] == 0) ? (*ins = RRA) : 0;
		(s[1] == 'r' && s[2] == 'b' && s[3] == 0) ? (*ins = RRB) : 0;
		(s[1] == 'r' && s[2] == 'r' && s[3] == 0) ? (*ins = RRR) : 0;
	}
}

int			parse_instructions(t_list **lst)
{
	char				*line;
	t_instruction		ins;
	t_list				*new;
	int					gnl_ret;
	int					len;

	while ((gnl_ret = get_next_line(0, &line)))
	{
		len = ft_strlen(line);
		if ( len < 2 || len > 3 )
			return (FALSE);
		check_instruction_then_convert(line, &ins);
		if (ins != ERROR)
		{
			new = ft_lstnew(&ins, sizeof(int));
			ft_lstadd_bot(lst, new);
		}
		else
			return (FALSE);
	}
	return (gnl_ret == -1 ? FALSE : TRUE);
}

void	print_lst(t_list *lst)
{
	int 	i = 0;
	while (lst != NULL)
	{
		ft_printf("%d eme elem of ins list:%d\n", i, *((int*)(lst->content)));
		lst = lst->next;
		i++;
	}
}

void	check_order(t_stack *stk, int tab_len)
{
	if (stk->b_len == 0 && stk->a_len == tab_len)
	{
		while (tab_len - 1)
		{
			if (stk->a[tab_len - 1] >= stk->a[tab_len - 2])
				break;
			tab_len--;
		}
		tab_len == 1 ? ft_printf("OK\n") : ft_printf("KO\n");
	}
	else
		ft_printf("KO\n");
}

int 	main(int argc, char const **argv)
{
	int		i;
	int		*tab;
	t_list	*ins_lst;
	t_stack	*stk;

	i = 0;
	ins_lst = NULL;
	if (argc >= 2 && args_check(argc, argv))
	{
		tab = parse_args(argc, argv);
		if (tab)
		{
			if(parse_instructions(&ins_lst))
			{
				stk = execute_instructions(ins_lst, tab, argc - 1);
				check_order(stk, argc - 1);
			}
			else
				//Codes to add here:free list
				ft_putendl_fd("Error", 2);
		}
		else
			ft_putendl_fd("Error", 2);
	}
	else
		ft_putendl_fd("Error", 2);
	return (0);
}
