
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

void	free_sstr(char **sstr)
{
	int		i;

	i = 0;
	if (sstr != NULL)
	{
		while (sstr[i])
		{
			free(sstr[i]);
			sstr[i] = NULL;
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
		stk->int_array != NULL ? free(stk->int_array) : 0;
		stk->b = NULL;
		stk->a = NULL;
		stk->origin_index = NULL;
		stk->int_array = NULL;
		free(stk);
		stk = NULL;
	}
}

void	free_sstr_and_exit(char **sstr)
{
	ft_putendl_fd("Error", 2);
	free_sstr(sstr);
	exit(0);
}


