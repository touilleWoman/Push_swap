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

# include <stdio.h>
# include "libft.h"

/*
** V_FLAG is to show stack at each operation
** F_FLAG is to read and write on file instead of STD
*/

# define INSTRUCTION_NB	11


# define V_FLAG	1 << 0
# define F_FLAG	1 << 1
# define INS_STDOUT 1 << 2
# define PUSH_SWAP  1 << 3
# define COUNT 1 << 4

typedef	struct	stack
{
	int		*a;
	int		a_len;
	int		*b;
	int		b_len;
	int		max_len;
	int		count;
}				t_stack;


typedef	enum	e_instruction
{
	SA = 0,
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
	ERROR,
}				t_instruction;


typedef struct	s_funs
{
	t_instruction	ins;
	void			(*f)(t_stack **stk, char flags, FILE *fp);
}				t_funs;

int				args_check(int argc, char const **argv, int *args_nb);
int				*parse_args_and_flags(int argc, char const **argv,
									char *flags, int *args_nb);
int				parse_instructions(t_list **lst, char flags);
t_stack			*execute_instructions(t_list *ins_lst, int *args, int nb_args, char *flags);
t_stack			*init_stack(int *args, int nb_args);

void			show_args(int *args, int args_nb);

void			show_stack(t_stack *stk);

void			usage(void);
void			free_list(t_list *lst);
void			free_all(t_stack *stk, t_list *ins_lst, int *args);
long long		a_to_long(const char *str);
int				is_flag_then_activate(char const *str, char *flags);
void			print_according_to_flags(char flags, FILE *fp, char *str,
									t_stack **stk);
void			print_lst(t_list *lst);

void			sort_an_increasing_tab(int *tab, int tab_len);


void			sa(t_stack **stk, char flags, FILE *fp);
void			sb(t_stack **stk, char flags, FILE *fp);
void			ss(t_stack **stk, char flags, FILE *fp);
void			pa(t_stack **stk, char flags, FILE *fp);
void			pb(t_stack **stk, char flags, FILE *fp);
void			ra(t_stack **stk, char flags, FILE *fp);
void			rb(t_stack **stk, char flags, FILE *fp);
void			rr(t_stack **stk, char flags, FILE *fp);
void			rra(t_stack **stk, char flags, FILE *fp);
void			rrb(t_stack **stk, char flags, FILE *fp);
void			rrr(t_stack **stk, char flags, FILE *fp);
void			algo(t_stack *stk, char flags, FILE *fp);
int				top1(t_stack *stk, char a_or_b);
int				top2(t_stack *stk, char a_or_b);
int				find_median(int *tab, int tab_len);
int				top1_exist(t_stack *stk, char a_or_b);
int				top2_exist(t_stack *stk, char a_or_b);
int				calculate_score(t_stack *stk);
void			try_ins(t_stack *cp, int *score, int flags);



t_stack		*launch_push_swap(int *args, char *flags, int args_nb);



#endif