/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:17:19 by llopez            #+#    #+#             */
/*   Updated: 2018/07/16 19:22:51 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_logic(a_list **a, a_list **b)
{
	if ((*a)->content > (*a)->next->content)
		sx(a, "sa");
	while (!sorted(a) && *a != get_minus(a))
		if (get_position_int(a, get_minus(a)) < a_listlen(*a) / 2)
			rx(a, "ra");
		else
			rrx(a, "rra");
	if (sorted(a) && *b == NULL)
		return ;
	rrx(a, "rra");
	sort_logic(a, b);
}
