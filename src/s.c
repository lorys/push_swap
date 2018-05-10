/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:04:58 by llopez            #+#    #+#             */
/*   Updated: 2018/05/10 21:59:35 by llopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		list_top(a_list *lst)
{
	while (lst != NULL && lst->prev != NULL)
		lst = lst->prev;
}

void		list_bottom(a_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
}


void		sa(a_list *a)
{
	int tmp;
	list_top(a);
	if (a->next != NULL && a != NULL)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
	}
}

void		sb(a_list *b)
{
	int tmp;
	list_top(b);
	if (b != NULL && b->next != NULL)
	{
		tmp = b->content;
		b->content = b->next->content;
		b->next->content = tmp;
	}
}

void		ss(a_list *a, a_list *b)
{
	sa(a);
	sb(b);
}
