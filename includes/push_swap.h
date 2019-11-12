/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:58:31 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/11 14:58:33 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INSTRUCTION_NB 11

#include "libft.h"

typedef	struct	stack
{
	int		*a;
	int		a_len;
	int		*b;
	int		b_len;
}				t_stack;

typedef	enum	e_instruction
{
	ERROR = 0,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
}				t_instruction;

typedef struct		s_funs
{
	t_instruction	ins;
	void			(*f)(t_stack**);
}					t_funs;
int			args_check(int argc, char const **argv);
int			*parse_args(int argc, char const **argv);
int			parse_instructions(t_list **lst);
t_stack		*execute_instructions(t_list *ins_lst, int *tab, int tab_len);
void		show_tab(int *tab, int tab_len);
void		show_stack(t_stack *stk);
void		error_freelst_exit(t_list *lst);

void		usage(void);
void		free_list(t_list *lst);


void		sa(t_stack **stk);
void		sb(t_stack **stk);
void		ss(t_stack **stk);
void		pa(t_stack **stk);
void		pb(t_stack **stk);
void		ra(t_stack **stk);
void		rb(t_stack **stk);
void		rr(t_stack **stk);
void		rra(t_stack **stk);
void		rrb(t_stack **stk);
void		rrr(t_stack **stk);






#endif