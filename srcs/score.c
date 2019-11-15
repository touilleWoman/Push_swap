/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:16:50 by jleblond          #+#    #+#             */
/*   Updated: 2019/11/15 14:16:52 by jleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void copy_stack(t_stack *stk, t_stack *cp)
{
	int	*aa;
	int	*bb;

	aa = (int*)malloc(sizeof(int) * stk->max_len);//???
	bb = (int*)malloc(sizeof(int) * stk->max_len);

	ft_memcpy(aa, stk->a, sizeof(int) * stk->max_len);
	ft_memcpy(bb, stk->b, sizeof(int) * stk->max_len);
	ft_memcpy(cp, stk, sizeof(t_stack));
	cp->a = aa;
	cp->b = bb;
}

void		try_ins(t_stack *stk, int *score, int flags)
{
	t_funs	funs[INSTRUCTION_NB] = {{SA, sa}, {SB, sb}, {SS, ss}, {PA, pa},
	{PB, pb}, {RA, ra}, {RB, rb}, {RR, rr}, {RRA, rra}, {RRB, rrb}, {RRR, rrr}
	};
	int	i;
	t_stack *cp;

	(void)flags;
	cp = (t_stack*)malloc(sizeof(t_stack));
	i = 0;
	while (i < INSTRUCTION_NB)
	{
		copy_stack(stk, cp);
		funs[i].f(&cp, 0 , NULL);
		score[i] = calculate_score(cp);
		// if (score[i] == 0)
		// 	break;
		// printf("run score test%d\n", score);
		free(cp->a);
		free(cp->b);
		i++;
	}


}




// int			score_sa(t_stack **stk, char flags, FILE *fp)
// {
// 	int		tmp;
// 	int		len;


// 	len = (*stk)->a_len;
// 	if (len > 1)
// 	{
// 		tmp = (*stk)->a[len - 1];
// 		(*stk)->a[len - 1] = (*stk)->a[len - 2];
// 		(*stk)->a[len - 2] = tmp;
// 	}
// }

// int			score_sb(t_stack **stk, char flags, FILE *fp)
// {
// 	int		tmp;
// 	int		len;


// 	len = (*stk)->b_len;
// 	if (len > 1)
// 	{

// 		tmp = (*stk)->b[len - 1];
// 		(*stk)->b[len - 1] = (*stk)->b[len - 2];
// 		(*stk)->b[len - 2] = tmp;
// 	}
// }

// int			score_ss(t_stack **stk, char flags, FILE *fp)
// {
// 	int		silence;

// 	silence = 0;
// 	sa(stk, 0, fp);
// 	sb(stk, 0, fp);
// }

// int			score_pa(t_stack **stk, char flags, FILE *fp)
// {

// 	if ((*stk)->b_len)
// 	{
// 		(*stk)->a_len++;
// 		(*stk)->a[(*stk)->a_len - 1] = (*stk)->b[(*stk)->b_len - 1];
// 		(*stk)->b_len--;
// 	}
// }

// int			score_pb(t_stack **stk, char flags, FILE *fp)
// {

// 	if ((*stk)->a_len)
// 	{
// 		(*stk)->b_len++;
// 		(*stk)->b[(*stk)->b_len - 1] = (*stk)->a[(*stk)->a_len - 1];
// 		(*stk)->a_len--;
// 	}
// }

// int			score_ra(t_stack **stk, char flags, FILE *fp)
// {
// 	int		tmp;
// 	int		len;

// 	len = (*stk)->a_len;
// 	if (len > 1)
// 	{
// 		tmp = (*stk)->a[len - 1];
// 		while (len - 1)
// 		{
// 			(*stk)->a[len - 1] = (*stk)->a[len - 2];
// 			len--;
// 		}
// 		(*stk)->a[0] = tmp;
// 	}
// }

// int			score_rb(t_stack **stk, char flags, FILE *fp)
// {
// 	int		tmp;
// 	int		len;


// 	len = (*stk)->b_len;
// 	if (len > 1)
// 	{
// 		tmp = (*stk)->b[len - 1];
// 		while (len - 1)
// 		{
// 			(*stk)->b[len - 1] = (*stk)->b[len - 2];
// 			len--;
// 		}
// 		(*stk)->b[0] = tmp;
// 	}
// }

// /*
// ** deactivate flags so information will not be printed again in ra and rb
// ** don't give *count, because ra and rb shouldn't be counted
// ** Same thing for ss and rrr.
// */
// int			score_rr(t_stack **stk, char flags, FILE *fp)
// {
// 	int		silence;

// 	silence = 0;
// 	ra(stk, 0, fp);
// 	rb(stk, 0, fp);
// }

// int			score_rra(t_stack **stk, char flags, FILE *fp)
// {
// 	int		tmp;
// 	int		len;
// 	int		i;


// 	i = 0;
// 	len = (*stk)->a_len;
// 	if (len > 1)
// 	{
// 		tmp = (*stk)->a[0];
// 		while (i < len - 1)
// 		{
// 			(*stk)->a[i] = (*stk)->a[i + 1];
// 			i++;
// 		}
// 		(*stk)->a[len - 1] = tmp;

// 	}
// }

// int			score_rrb(t_stack **stk, char flags, FILE *fp)
// {
// 	int		tmp;
// 	int		len;
// 	int		i;


// 	i = 0;
// 	len = (*stk)->b_len;
// 	if (len > 1)
// 	{
// 		tmp = (*stk)->b[0];
// 		while (i < len - 1)
// 		{
// 			(*stk)->b[i] = (*stk)->b[i + 1];
// 			i++;
// 		}
// 		(*stk)->b[len - 1] = tmp;

// 	}
// }

// int			score_rrr(t_stack **stk, char flags, FILE *fp)
// {
// 	int		silence;

// 	silence = 0;
// 	rra(stk, 0, fp);
// 	rrb(stk, 0, fp);
// }

