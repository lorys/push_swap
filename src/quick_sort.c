/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:16:16 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:23:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort_rev(a_list **a, a_list **b)
{
	while (*b != get_max(b))
	{
		if (get_position_int(b, get_max(b)) < a_listlen(*b) / 2)
			rx(b, "rb");
		else
			rrx(b, "rrb");
	}
	if ((*b)->content == get_max(b)->content)
		px(b, a, "pa");
	if (*b != NULL)
		quick_sort_rev(a, b);
}

void		quick_sort(a_list **a, a_list **b)
{
	int mediane;

	while (a_listlen(*a) > 2 && !sorted(a))
	{
		mediane = get_mediane(*a);
		while (get_minus(a)->content < mediane)
		{
			if (sorted(a) && *b == NULL)
				return ;
			if (sorted(a) && get_max(a)->content > get_max(b)->content && \
					lastoflist(a) == get_max(a) && \
					(*a)->content > get_max(b)->content)
				break ;
			if ((*a)->content < mediane)
				px(a, b, "pb");
			else
				rx(a, "ra");
		}
		if (!sorted(a) && a_listlen(*a) == 2)
			sx(a, "sa");
	}
	quick_sort_rev(a, b);
}
