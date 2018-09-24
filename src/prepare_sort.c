/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:18:07 by llopez            #+#    #+#             */
/*   Updated: 2018/09/24 15:31:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort_part(t_lst **a, t_lst **b)
{
	while (get_max(b) != *b)
	{
		if (t_lstlen(*b) / 2 > get_position_int(b, get_max(b)))
			rx(b, "rb");
		else
			rrx(b, "rrb");
	}
	px(b, a, "pa");
	if (!sorted(a) || *b != NULL)
		quick_sort_part(a, b);
}

void		prepare_sort(t_lst **a, t_lst **b)
{
	if (t_lstlen(*a) > 3)
	{
		if (t_lstlen(*a) < 10)
		{
			while (*a != get_minus(a))
			{
				if (t_lstlen(*a) / 2 < get_position_int(a, get_minus(a)))
					rrx(a, "rra");
				else
					rx(a, "ra");
			}
		}
		quick_sort(a, b);
		quick_sort_part(a, b);
	}
	else
		sort_logic(a, b);
}
