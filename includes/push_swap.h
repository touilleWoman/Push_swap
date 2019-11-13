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

# include "libft.h"

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


# define	V_FLAG		1 << 0
# define	C_FLAG		1 << 1
# define	SHOW_INS	1 << 2

typedef struct	s_funs
{
	t_instruction	ins;
	void			(*f)(t_stack**, char *flags);
}				t_funs;
int				args_check(int argc, char const **argv);
int		*parse_args_and_flags(int argc, char const **argv, char *flags);
int				parse_instructions(t_list **lst);
t_stack		*execute_instructions(t_list *ins_lst, int *args, int nb_args, char *flags);
t_stack			*init_stack(int *args, int nb_args);

void			show_args(int *args, int args_nb);
void			show_stack(t_stack *stk);
void			error_freelst_exit(t_list *lst);

void			usage(void);
void			free_list(t_list *lst);
void		free_all(t_stack *stk, t_list *ins_lst, int *args);




void			sa(t_stack **stk, char *flags);
void			sb(t_stack **stk, char *flags);
void			ss(t_stack **stk, char *flags);
void			pa(t_stack **stk, char *flags);
void			pb(t_stack **stk, char *flags);
void			ra(t_stack **stk, char *flags);
void			rb(t_stack **stk, char *flags);
void			rr(t_stack **stk, char *flags);
void			rra(t_stack **stk, char *flags);
void			rrb(t_stack **stk, char *flags);
void			rrr(t_stack **stk, char *flags);



t_stack		*launch_algo(int *args, int argc, char *flags);



#endif