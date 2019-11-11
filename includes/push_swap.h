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

typedef	struct	stack
{
	int		*a;
	int		a_len;
	int		*b;
	int		b_len;
}				t_stack;

void	show_tab(int *tab, int tab_len);
t_stack		*execute_commands(char *commands, int *tab, int tab_len);
void		show_stack(t_stack *stk);




#endif