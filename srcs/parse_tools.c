#include "push_swap.h"

int			duplicate_int_exist(int *int_array, int nb_int)
{
	int		i;
	int		j;

	i = 0;
	j = i + 1;
	while (i < nb_int - 1)
	{
		while (j < nb_int)
		{
			if (int_array[i] == int_array[j])
				return (TRUE);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (FALSE);
}

int			get_flags_nb_and_activate(int argc, char const **argv, char *flags)
{
	int		i;
	int		flag_nb;

	flag_nb = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag_then_activate(argv[i], flags))
			flag_nb++;
		i++;
	}
	return (flag_nb);
}
