/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:22:39 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/20 14:22:43 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_min_in_scoretab(int *score_tab, int len, int *min_score)
{
	int		i;
	int		min_fun_index;

	*min_score = 1000;
	i = 0;
	min_fun_index = 0;
	while (i < len)
	{
		if (score_tab[i] < *min_score)
		{
			min_fun_index = i;
			*min_score = score_tab[i];
		}
		i++;
	}
	return (min_fun_index);
}

void		execute_ins(int fun_index, int flags, FILE *fp, t_stack *stk)
{
	static t_funs	funs_for_try[9] = {{SA, sa}, {SB, sb}, {SS, ss}, {RA, ra},
	{RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};

	funs_for_try[fun_index].f(&stk, flags, fp);
}

int			get_min_score(t_stack *stk, int *min_fun_index, int *min_score)
{
	int	score_tab[9];

	if (try_ins(stk, score_tab))
	{
		*min_fun_index = find_min_in_scoretab(score_tab, 9, min_score);
		return (TRUE);
	}
	return (FALSE);
}

int			execute_if_score_smaler(t_stack *stk, char flags, FILE *fp)
{
	int	min_fun_index;
	int	min_score;
	int present_score;

	while (TRUE)
	{
		get_min_score(stk, &min_fun_index, &min_score);
		present_score = calculate_score(stk);
		if (min_score < present_score)
			execute_ins(min_fun_index, flags, fp, stk);
		if (min_score == 0 || min_score >= present_score)
			break ;
	}
	return (min_score);
}

/*
** if stacks can be sorted without pb(min_score == 0),
** then don't start optimised insertion algo
*/

void		choose_algo(t_stack *stk, char flags, FILE *fp)
{
	int		min_score;
	t_stack *cp;

	cp = copy_stack(stk);
	if (cp)
	{
		min_score = execute_if_score_smaler(cp, 0, fp);
		free_push_swap_stack(cp);
		if (min_score == 0)
		{
			execute_if_score_smaler(stk, flags, fp);
			return ;
		}
	}
	optimised_insertion_algo(stk, flags, fp);
}
