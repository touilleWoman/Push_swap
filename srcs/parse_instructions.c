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

int			check_instruction_then_convert(char *s, t_instruction *ins)
{
	int		ret;

	ret = TRUE;
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
	else
		ret = FALSE;
	return (ret);
}

int			get_fd_if_flagf_activated(char flags)
{
	int			fd;
	char		filename[100];
	int			len;

	if (flags & F_FLAG)
	{
		ft_printf("Pleases give the path of file:\n");
		if (fgets(filename, 100, stdin))
		{
			len = ft_strlen(filename);
			if (filename[len - 1] == '\n')
				filename[len - 1] = 0;
			fd = open(filename, O_RDONLY);
			if (fd < 0)
				ft_putendl_fd("Failed to read file!", 2);
		}
		else
			return (-1);
	}
	else
		fd = 0;
	return (fd);
}

int			parse_instructions(t_list **lst, char flags)
{
	char				*line;
	t_instruction		ins;
	int					gnl_ret;
	int					fd;
	int					all_ins_good;

	fd = get_fd_if_flagf_activated(flags);
	if (fd < 0)
		return (FALSE);
	while ((gnl_ret = get_next_line(fd, &line)))
	{
		all_ins_good = check_instruction_then_convert(line, &ins);
		free(line);
		if (all_ins_good == FALSE)
			return (FALSE);
		ft_lstadd_bot(lst, ft_lstnew(&ins, sizeof(int)));
	}
	return (gnl_ret == -1 ? FALSE : TRUE);
}
