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

# include "libft.h"
# include <stdio.h>

/*
** V_FLAG is to show stack at each operation
** F_FLAG is to read and write on file instead of STDIN STDOUT
*/

# define INSTRUCTION_NB	11
# define V_FLAG	1 << 0
# define F_FLAG	1 << 1
# define INS_STDOUT 1 << 2
# define PUSH_SWAP  1 << 3
# define COUNT 1 << 4

/*
** in checker, only a, a_len, b, b_len are used
*/
typedef	struct	s_stack
{
	int		*a;
	int		a_len;
	int		*b;
	int		b_len;
	int		max_len;
	int		count;
	int		*origin_index;
	int		*int_array;
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
}				t_instruction;

typedef struct	s_funs
{
	t_instruction	ins;
	void			(*f)(t_stack **stk, char flags, FILE *fp);
}				t_funs;

/*
** parse
*/
int				*parse_args_and_flags(int argc, char const **argv,
									char *flags, int *nb_int);
int				parse_instructions(t_list **lst, char flags);
t_stack			*execute_instructions(t_list *ins_lst, int *int_array,
										int nb_int, char *flags);
t_stack			*init_stack_checker(int *int_array, int nb_int);
t_stack			*init_stack_push_swap(int *int_array, int nb_int,
									int *origin_index, int *index);
void			free_list(t_list *lst);
void			usage(void);
int				is_integer_string(const char *str);
int				is_flag_string(char const *str);
int				get_flags_nb_and_activate(int argc, char const **argv,
										char *flags);
int				is_space_separated_integer_string(const char *str);
int				duplicate_int_exist(int *int_array, int nb_int);

/*
** instructions
*/

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

/*
** algo
*/

t_stack			*launch_push_swap(int *int_array, char *flags, int nb_int);
int				calculate_score(t_stack *stk);
int				try_ins(t_stack *cp, int *score);
t_stack			*copy_stack(t_stack *stk);
int				*copy_int_array(int	*tab, int tab_len);
int				both_ab_right_order(t_stack *stk);
int				execute_if_score_smaler(t_stack *stk, char flags, FILE *fp);
void			choose_algo(t_stack *stk, char flags, FILE *fp);
void			perfect_b_algo(t_stack *stk, char flags, FILE *fp);
void			sort_an_increasing_tab(int *tab, int tab_len);
int				find_int_from_index_dict(int *int_array, int *index,
										int elem_index, int nb_int);
int				best_score_algo(t_stack *stk, char flags, FILE *fp,
								int last_algo_nb);
void			free_sstr(char **sstr);
void			free_push_swap_stack(t_stack *stk);
void			free_sstr_and_exit(char **sstr);

/*
** display
*/
void			show_stack(t_stack *stk, int a_len, int b_len);
void			print_lst(t_list *lst);
void			print_one_line(int elem_a, int elem_b,
						t_bool a_exist, t_bool b_exist);
void			print_according_to_flags(char flags, FILE *fp, char *str,
									t_stack **stk);

#endif
