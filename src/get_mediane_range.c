
#include "push_swap.h"

int			get_mediane_range(t_lst *a, int len)
{
	t_lst	*sort_lst;
	int		tmp;

	sort_lst = sort_list(a);
	tmp = get_maillon(&sort_lst, (len / 2))->content;
	free_list(sort_lst);
	return (tmp);
}
