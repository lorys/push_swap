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

void		quick_sort_rev(t_lst **a, t_lst **b)
{
	int mediane;

	mediane = get_mediane(*b);
	while (*b != NULL && get_max(b)->content > mediane)
	{
		if ((*b)->content > mediane)
			px(b, a, "pa");
		else
			rx(b, "rb");
		if (!sorted(a))
			break;
	}
	while (!sorted(a))
		px(a, b, "pb");
	if (*b != NULL)
		quick_sort_rev(a, b);
}

void		quick_sort(t_lst **a, t_lst **b)
{
	int mediane;

	mediane = get_mediane(*a);
	while (get_minus(a)->content < mediane)
	{ 
		if ((sorted(a) && *b == NULL) \
			|| (sorted(a) && (*a)->content > \
			get_max(b)->content))
				return ;
		if ((*a)->content < mediane)
			px(a, b, "pb");
		else
			rx(a, "ra");
	}
	if (!sorted(a))
		quick_sort(a, b);
	while (*b != NULL && get_max(b)->content > mediane)
	{ 
		if ((*b)->content > mediane)
			px(b, a, "pa");
		else
			rx(b, "rb");
		if (!sorted(a))
			break;
	} 
	if (!sorted(a))
		quick_sort(a, b);
}
