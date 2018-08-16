/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:16:16 by llopez            #+#    #+#             */
/*   Updated: 2018/08/01 16:04:29 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		quick_sort(t_lst **a, t_lst **b)
{
	int	mediane;

	mediane = get_mediane(*a, *b);
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
}
