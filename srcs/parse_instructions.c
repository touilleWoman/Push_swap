/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:44:28 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/12 19:44:32 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** convert instructions from string to emum t_instructions
*/

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