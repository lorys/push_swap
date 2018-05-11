/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:04:58 by llopez            #+#    #+#             */
/*   Updated: 2018/05/11 20:14:11 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		list_top(a_list **lst)
{
	while ((*lst)->prev != NULL && lst->prev->null != 1)
		(*lst) = (*lst)->prev;
	return ((*lst));
}

void		list_bottom(a_list **lst)
{
	while ((*lst)->next != NULL)
		(*lst) = (*lst)->next;
	return (lst);
}

void		sx(a_list **x)
{
	int	tmp;

	(void)tmp;
	if (*x != NULL)
	{
		list_top(*x);
		if ((*x)->next != NULL)
		{
			tmp = (*x)->next->content;
			(*x)->next->content = (*x)->content;
			(*x)->content = tmp;
		}
	}
}

void		ss(a_list **a, a_list **b)
{
	sx(a);
	sx(b);
}
