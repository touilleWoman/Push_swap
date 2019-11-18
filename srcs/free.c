
#include "push_swap.h"

void	free_list(t_list *lst)
{
	t_list	*tmp;

	while (lst != NULL)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

void		free_sstr(char **sstr, int sstr_len)
{
	int		i;

	i = 0;
	if (sstr != NULL)
	{
		while (i < sstr_len)
		{
			if (sstr[i] != NULL)
			{
				free(sstr[i]);
				sstr[i] = NULL;
			}
			i++;
		}
		free(sstr);
		sstr = NULL;
	}
}

void	free_push_swap_stack(t_stack *stk)
{
	if (stk != NULL)
	{
		stk->b != NULL ? free(stk->b) : 0;
		stk->a != NULL ? free(stk->a) : 0;
		stk->origin_index != NULL ? free(stk->origin_index) : 0;
		stk->args != NULL ? free(stk->args) : 0;
		stk->b = NULL;
		stk->a = NULL;
		stk->origin_index = NULL;
		stk->args = NULL;
		free(stk);
		stk = NULL;
	}
}

