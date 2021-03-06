/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 19:16:53 by llopez            #+#    #+#             */
/*   Updated: 2018/09/20 13:15:23 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_insert(t_lst **a)
{
	t_lst	*start;
	int		tmp;

	start = *a;
	while ((*a)->next != NULL)
	{
		if ((*a)->content > (*a)->next->content)
		{
			tmp = (*a)->content;
			(*a)->content = (*a)->next->content;
			(*a)->next->content = tmp;
		}
		*a = (*a)->next;
	}
	*a = start;
	if (!sorted(a))
		sort_insert(a);
}
